/*
* Title: hw4_3
* Abstract: Sorts topologically w/ Kahn's algorithm
* ID: 6081
* Name: Christopher Boyd
* Date: 11-30-2020
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// Struct obj
typedef struct GraphObj {
    int eSrc, eDest;
} GraphObj;

// Function prototypes
void kahn(GraphObj edgeList[25], int inDegs[25], int edge, int vertex);


// Function: MAIN
int main() {
    
    int vertices, edges;
    int incDegrees[25] = {0};
    GraphObj graph[25];
    
    cin >> vertices >> edges;
    // Make array of structs containing an edge src and dest
    for (int i = 0; i < edges; i++) {
        cin >> graph[i].eSrc;
        cin >> graph[i].eDest;
    }
    
    // Set up mark array for incoming degrees
    for (int i = 0; i < edges; i++) {
        incDegrees[graph[i].eDest] += 1;
    }
    
    // Compute route using kahn's algorithm
    kahn(graph, incDegrees, edges, vertices);
    
    return 0;
}

// Function: KAHN
void kahn(GraphObj edgeList[25], int inDegs[25], int edge, int vertex) {
    
    bool isCycle = false;
    int currentNode;
    vector<int> outputOrder;
    queue<int> kq;
    
    // Print out init degree list before beginning to modify it
    for (int i = 0; i < vertex; i++) {
        cout << "In-degree[" << i << "]:" << inDegs[i] << endl;
    }
    
    // *!* Queue operation -- Kahn Algorithm core functionality *!*
    for (int j = 0; j < vertex; j++) {
        // Update queue with new 0 degree nodes
        for (int i = 0; i < vertex; i++) {
            if(inDegs[i] == 0) {
                kq.push(i);
                // Set -1 to denote node inaccessible after queue add
                inDegs[i] = -1;
            }
        }
        
        currentNode = kq.front();
        
        for (int i = 0; i < edge; i++) {
            if (edgeList[i].eSrc == currentNode) {
                inDegs[edgeList[i].eDest] -= 1;   
            }
        }
        
        // Construct order and remove current 0 degree node from queue
        outputOrder.push_back(kq.front());
        kq.pop();
    }
    
    // Check if graph is cyclical by whether vertices are repeated in results
    vector<int> sortVertices = outputOrder;
    sort(sortVertices.begin(), sortVertices.end());
    for (int i = 0; i < vertex - 1; i++) {
        if(sortVertices[i] == sortVertices[i+1]) {
            isCycle = true;
            break;
        }
    }
    
    // Print traversal order of algorithm
    if (!isCycle) {
        cout << "Order:";
        for (int i = 0; i < vertex - 1; i++) {
            cout << outputOrder[i] << "->";
        }
        cout << outputOrder[vertex - 1] << endl;        
    } else {
        cout << "No Order:" << endl;
    }
}
