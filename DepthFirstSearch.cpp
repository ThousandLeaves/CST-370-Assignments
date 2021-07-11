/*
* Title: hw3_3
* Abstract: Implements the DFS algorithm
* ID: 6081
* Name: Christopher Boyd
* Date: 11-16-2020
*/

#include <iostream>
#include <vector>
#include <stack> // May not be necessary with recursive implementation?

using namespace std;

// Global scope counter variable
int G_CTR = 0;

void dfs(vector<vector<vector <int>>> & vVector, int vTree[30], int vertex);

// Function: MAIN
int main() {
    
    int vertices, edges, e1, e2; // e1 - Src vertex, e2 - Destination (end of edge)
    int vertexTree[30] = {0};
    vector<vector<vector <int>>> edgeInfo;
    
    // Build vector top element: Vertices
    cin >> vertices >> edges;
    for (int i = 0; i < vertices; i++) {
        edgeInfo.push_back(vector<vector<int>>());
    }
    
    // Build vector mid/low element: Edges/points
    for(int i = 0; i < edges; i++) {
        cin >> e1 >> e2;
        // Build new edge
        edgeInfo[e1].push_back(vector<int>());
        // Insert points at back element
        edgeInfo[e1][edgeInfo[e1].size() -1].push_back(e1);
        edgeInfo[e1][edgeInfo[e1].size() -1].push_back(e2);
    }
    
    for(int i = 0; i < vertices; i++) {
        if (vertexTree[i] == 0) {
            // Count incremented each time function is run
            dfs(edgeInfo, vertexTree, i);
        }
    }
    
    for(int i = 0; i < vertices; i++) {
        if(vertexTree[i] != 0) {
            cout << "Mark[" << i << "]:" << vertexTree[i] << endl;
        }
    }
    return 0;
}

// Function: DFS Algorithm
void dfs(vector<vector<vector <int>>> & vVector, int vTree[30], int vertex) {
    
    G_CTR += 1;
    vTree[vertex] = G_CTR;
    for(int i = 0; i < vVector[vertex].size(); i++) {
        if(vTree[vVector[vertex][i][1]] == 0) {
            dfs(vVector, vTree, vVector[vertex][i][1]);            
        }
    }

}
