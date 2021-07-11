/*
* Title: hw2_1
* Abstract: Converts a digraph into an adjacency list.
* ID: 6081
* Name: Christopher Boyd
* Date: 11-08-2020
*/

#include <iostream>
#include <utility>

using namespace std;

int main () {
    
    int minNum, numVertices, numEdges;
    int vIn, eIn;
    int edgeInformation[50][50] = {-1};
    
    
    cin >> numVertices;
    cin >> numEdges;
    
    // Set all elements to -1, indicates unused array space
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < 50; j++) {
            edgeInformation[i][j] = -1;
        }
    }    
    
    // Fill 2d array with rest of edgeInformation
    for (int i = 0; i < numEdges; i++) {
        cin >> vIn;
        cin >> eIn;
        // Find empty spot in array
        for (int j = 0; j < numEdges; j++) {
            if (edgeInformation[vIn][j] == -1) {
                edgeInformation[vIn][j] = eIn;
                break;
            }
        }
    }
    
    // Sort each row in edgeInformation array
    for (int i = 0; i < numVertices; i++) {
        // Selection sorting algorithm
        for (int j = 0; j < numEdges - 1; j++) {
            minNum = j;
            for (int k = j + 1; k < numEdges; k++) {
                // Exclude empty '-1' array elements from sort
                if (edgeInformation[i][k] < edgeInformation[i][minNum] &&
                    edgeInformation[i][k] != -1 && edgeInformation[i][minNum] != -1) {
                    minNum = k;
                }
                swap(edgeInformation[i][minNum], edgeInformation[i][j]);
            }
        }
    }
    
    // Print contents of array in adjacency list form
    for (int i = 0; i < numVertices; i++) {
        cout << i;
        if (edgeInformation[i][0] != -1) {
            cout << "->";
        }
        for (int j = 0; j < numEdges; j++) {
            if (edgeInformation[i][j] != -1) {
                cout << edgeInformation[i][j];
                if (edgeInformation[i][j + 1] != -1) {
                    cout << "->";
                }
            }
        }
        cout << endl;
    }
    
    return 0;
}
