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

int *primes = new int[78500];
int primeCounter = 0;

int primeSieve(int upperBound){
    
    int upperBoundSquareRoot = (int)sqrt((double)upperBound);
    bool *isComposite = new bool[upperBound + 1];
    primeCounter = 0;

    memset(isComposite, 0, sizeof(bool) * (upperBound + 1));
    for (int m = 2; m <= upperBoundSquareRoot; m++) {
          if (!isComposite[m]) {
                primes[primeCounter] = m;
                primeCounter++;
                for (int k = m * m; k <= upperBound; k += m)
                      isComposite[k] = true;
          }
    }
    for (int m = upperBoundSquareRoot; m <= upperBound; m++)
          if (!isComposite[m]){
                primes[primeCounter] = m;
                primeCounter++;
          }
    delete [] isComposite;
    cout << endl << "Number of Primes: " << primeCounter << endl;

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
    
    double phiValue = number;
    int numberSR = ceil(sqrt(number));
    bool *array = new bool[number + 1];
    memset(array, 0, sizeof(bool) * (number + 1));

    //printArray(array, number + 1);
    
    for(int i = 2; i <= number; i++){
        if(!array[i]){
            
            if(number % i == 0){
                cout << i << endl;
                for(int j = i; j <= number; j += i){
                    array[j] = true;
                }
                //printArray(array, numberSR + 1);
                //cout << phiValue << endl;
                phiValue *= (float)(1-(1/(float)i));
                //cout << phiValue << endl;
            }
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
    
    //int upperLimit = 1000000;
    
    //primeSieve(upperLimit);
    
    int number = 1000000;
    int phiVal = phi(number);
    
    cout << "phi value for " << number << ": " << phiVal;
    

    return 0;
}

