/*
* Title: hw5_1
* Abstract: Implements max heap and heap functions
* ID: 6081
* Name: Christopher Boyd
* Date: 12-06-2020
*/

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

// Function prototypes
bool isHeap(int heap[75], int hSize);
int searchHeap(int heap[75], int hSize, int val);
void heapify(int heap[75], int hSize);
void parseInputs(string comms[75], int heap[75], int cSize, int &hSize);

// FUNCTION: main
int main() {
    
    // Variables
    bool heapTest;
    int heapSize, commandSize;
    int heap[75] = {0};
    string commands[75] = {"0"}; 
    
    // Get user inputs
    cin >> heapSize;
    for (int i = 0; i < heapSize; i++) {
        cin >> heap[i + 1];
    }
    cin >> commandSize;
    for (int i = 0; i < commandSize; i++) {
        cin >> commands[i];
        // Adjust command size to account for how cin adds elements to arrays
        if(commands[i] == "delete" || commands[i] == "insert") {
            commandSize += 1;
        } else if (commands[i] == "update") {
            commandSize += 2;
        }
    }
    cout << endl;
    
    if (!(heapTest = isHeap(heap, heapSize))){
        cout << "This is NOT a heap." << endl;
        // Non-heap structure detected, use heapify to build heap
        heapify(heap, heapSize);
        
    } else {
        cout << "This is a heap." << endl;
    };
    
    parseInputs(commands, heap, commandSize, heapSize);
    
    return 0;
}

// FUNCTION: isHeap
bool isHeap(int heap[75], int hSize) {
    for (int i = 1; i <= hSize; i++) {
        if (!(heap[i] <= heap[i/2]) && i > 1) {
            return false;
        }
    }
    return true;
}

// FUNCTION: heapify
void heapify(int heap[75], int hSize) {
    
    // Builds heap using bottom-up construction
    for (int i = hSize / 2; i >= 1; i--) {

        int k = i;
        int v = heap[k];
        bool isHeap = false;

        do {
            int j = 2 * k;
            if (j < hSize) {
                if (heap[j] < heap[j + 1]) {
                    j += 1;
                }
            }
            if (v >= heap[j]) {
                isHeap = true;
            } else {
                heap[k] = heap[j];
                k = j;
            }
        } while (not isHeap && (2 * k <= hSize));

        heap[k] = v;
    }
}

// FUNCTION: searchHeap
int searchHeap(int heap[75], int hSize, int val) {
    for (int i = 1; i <= hSize; i++) {
        if (heap[i] == val) {
            return i;
        }
    }
    return -1;
}

// FUNCTION: parseInputs
void parseInputs(string comms[75], int heap[75], int cSize, int &hSize) {
    for (int i = 0; i < cSize; i++) {
        // Cmd: displayMax
        if (comms[i] == "displayMax") {
            cout << heap[1] << endl;
            
        } else if (comms[i] == "display") {
            // Cmd: display
            for (int j = 1; j <= hSize; j++) {
                cout << heap[j] << " ";
            }
            cout << endl;
            
        } else if (comms[i] == "deleteMax") {
            // Cmd: deleteMax
            int tmp = heap[1];
            heap[1] = heap[hSize];
            heap[hSize] = tmp;
            hSize -= 1;
            // Rebuild heap after removing top element
            heapify(heap, hSize);
            
        } else if (comms[i] == "delete") {
            // Cmd: delete
            int deletedVal = searchHeap(heap, hSize, stoi(comms[i + 1]));
            // Only run deletion & heapify if val is found
            if (deletedVal != -1) {
                int tmp = heap[deletedVal];
                heap[deletedVal] = heap[hSize];
                heap[hSize] = tmp;
                hSize -= 1;
                // Rebuild heap after operation
                heapify(heap, hSize);
            }
            // Jump over int modifier for del cmd
            i++;
            
        } else if (comms[i] == "insert") {
            // Cmd: Insert
            hSize += 1;
            heap[hSize] = stoi(comms[i + 1]);
            // Rebuild heap after operation
            heapify(heap, hSize);
            
        } else if (comms[i] == "update") {
            // Cmd: Update
            heap[stoi(comms[i + 1])] = stoi(comms[i + 2]);
            // Rebuild heap after operation
            heapify(heap, hSize);
            // Jump over both int modifiers for update cmd
            i += 2;
        }
    } 
}
