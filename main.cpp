/* 
 * File:   main.cpp
 * Author: elliot
 *
 * Created on May 3, 2015, 12:48 PM
 */

#include <cstdlib>
#include <iostream>
#include <math.h>
#include <Windows.h>


using namespace std;

unsigned long long int rpfCounter = 0;
int primeCounter;

int *primes = new int[78500];
int long phiValue = 0;
int numberSR = 0;

/**
 * Credit: http://www.algolist.net/Algorithms/Number_theoretic/Sieve_of_Eratosthenes
 * @param upperBound
 */
void primeSieve(int upperBound) {
    int upperBoundSquareRoot = (int)sqrt((double)upperBound);
    bool *isComposite = new bool[upperBound + 1];
    primeCounter = 0;

    memset(isComposite, 0, sizeof(bool) * (upperBound + 1));
    for (int m = 2; m <= upperBoundSquareRoot; m++) {
          if (!isComposite[m]) {
                primes[primeCounter] = m;
                primeCounter++;
                for (int k = m; k <= upperBound; k += m)
                      isComposite[k] = true;
          }
    }
    for (int m = upperBoundSquareRoot; m <= upperBound; m++)
          if (!isComposite[m]){
                primes[primeCounter] = m;
                primeCounter++;
          }
    delete [] isComposite;
    //cout << endl << "Number of Primes: " << primeCounter << endl;
    for(int i = 0; i <20; i++){
        cout << primes[i] <<" ";
    }
    cout<<endl;

}

void printArray(bool* array, int size){
    for(int i = 0; i < size; i++){
        if(array[i])
            cout << "1, ";
        else
            cout << "0, ";
    }
    cout << endl;
}

int phi(int number){
    
    phiValue = number;
    numberSR = ceil(sqrt(number));

    for(int i = 0; primes[i] <= 7; i++){
            if(number%primes[i] == 0){

                //printArray(array, numberSR + 1);
                //cout << phiValue << endl;
                phiValue = phiValue * (1-(1/(float)primes[i]));
                cout << primes[i] << " ";
                cout << phiValue << endl;
            }

    }
    
    if(phiValue == number){
        phiValue--;
    }
    
    
    return phiValue;

}

/*
 * 
 */
int main(int argc, char** argv) {
    
    int upperLimit = 8;
    
    primeSieve(upperLimit);
    
    cout << "phi of upperLimit: " << phi(upperLimit) << endl;
    
   // for(int i = 2; i <= upperLimit; i++){
        //rpfCounter += (int)phi(i);
    //}
    
    //cout << "Total # of reduced proper fractions with denominator <= " << upperLimit << ": " << rpfCounter;
    
    
    

    return 0;
}

