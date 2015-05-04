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
    
    int phiValue = number;
    int numberSR = ceil(sqrt(number));
    bool *array = new bool[number + 1];
    memset(array, 0, sizeof(bool) * (number + 1));

    for(int i = 2; i <= number; i++){
        if(!array[i]){
            
            if(number % i == 0){
                //cout << i << endl;
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
    delete [] array;
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    int long upperLimit = 1000000;
    
    
    for(int i = 2; i <= upperLimit; i++){
        rpfCounter += (int)phi(i);
    }
    
    cout << "Total # of reduced proper fractions with denominator <= " << upperLimit << ": " << rpfCounter;
    
    
    

    return 0;
}

