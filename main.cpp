/* 
 * File:   main.cpp
 * Author: elliot
 *
 * Created on May 3, 2015, 12:48 PM
 */

#include <cstdlib>
#include <iostream>
#include <math.h>


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

int phi(int number){
    
    int phiValue = number - 1;
    int numberSR = ceil(sqrt(number));
    //cout << numberSR << endl;
    
    

    for(int i = 2; i <= numberSR; i++){
        if(number % i == 0){
            if(number/i == numberSR){
                return i * i - i;
            }
            //cout << i << endl;
            //cout << number/i << endl;
            cout << (i-1) * phi(number/i) << endl;
            return i * phi(number/i);
        }
    }
    
    return phiValue;
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    int upperLimit = 1000000;
    
    primeSieve(upperLimit);
    
    int number = 114;
    int phiVal = phi(number);
    
    cout << "phi value for " << number << ": " << phiVal;

    return 0;
}

