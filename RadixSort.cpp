/*
* Title: hw6_1
* Abstract: Implements the radix sort
* ID: 6081
* Name: Christopher Boyd
* Date: 12-12-2020
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Struct obj
typedef struct Container {
    vector<int> arr;
} Container;

// Function prototypes
void radixSort(int rArr[], Container cArr[], int sizeA, int nDigits);
void printArray(int rArr[], int sizeA);
void emptyVector(Container cont[]);

// FUNCTION: main
int main() {
    
    int mainArray[30] = {0};
    int arraySize;
    int digits = 0;
    Container cont[10];

    // Get user inputs
    cin >> arraySize;
    for (int i = 0; i < arraySize; i++) {
        cin >> mainArray[i];
        
        // Determine # digits in largest input
        int tmpNum = log10(mainArray[i]) +1;
        if (tmpNum > digits) {
            digits = tmpNum;
        }
    }
    
    radixSort(mainArray, cont, arraySize, digits);
    return 0;
}

void radixSort(int rArr[], Container cArr[], int sizeA, int nDigits) {
    int modLv, msd, arrHolder;

    // Sorts n times based on number of digits of largest input
    for (int i = 1; i <= nDigits; i++) {
        modLv = pow(10, i);
        
        for (int j = 0; j < sizeA; j++) {
            msd = (rArr[j] % modLv) / (modLv / 10);
            cArr[msd].arr.push_back(rArr[j]);
        }
        
        // Place bucket content in order into old radix array
        arrHolder = 0;
        for (int k = 0; k < 10; k++) {
            for (const auto& value: cArr[k].arr ) {
                rArr[arrHolder] = value;
                arrHolder++;
            }
        }
        
        // Empty vector for next iteration
        emptyVector(cArr);
        // Print intermediary array here
        printArray(rArr, sizeA);
    }
}

// FUNCTION: emptyVector
void emptyVector(Container cont[]) {
    for (int i = 0; i < 10; i++) {
        if (!cont[i].arr.empty()) {
            cont[i].arr.clear();
        }
    }
}

// FUNCTION: printArray
void printArray(int rArr[], int sizeA) {
    for (int i = 0; i < sizeA; i++) {
        cout << rArr[i] << " ";
    }
    cout << endl;
}
