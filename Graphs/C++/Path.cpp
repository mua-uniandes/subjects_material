//
//  Path.cpp
//  Graphs
//
//  Created by NicolasCardozo on 5/29/19.
//  Copyright © 2019 NicolasCardozo. All rights reserved.
//

#include <stdio.h>

#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> nodes[], int e1, int e2) {
    nodes[e1].push_back(e2);
    nodes[e2].push_back(e1);
}

void printGraph(vector<int> nodes[]) {
    for (int v = 0; v <= nodes->size(); ++v){
        cout << "\n Adjacency list of vertex " << v << "\n";
        for (auto x : nodes[v])
            cout << "(" << v << ", " << x << ")\n";
        printf("\n");
    }
}

void path(vector<int> nodes, int w, int v) {
    
}

int main() {
    int n, nEdges, e1, e2;
    cin >> n;
    vector<int> nodes[n];
    cin >> nEdges;
    for(int i=0; i<nEdges; i++) {
        cin >> e1 >> e2;
        addEdge(nodes, e1, e2);
    }
    printGraph(nodes);
    return 0;
}
