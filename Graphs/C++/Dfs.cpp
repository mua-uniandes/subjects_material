//
//  Dfs.cpp
//  Graphs
//
//  Created by NicolasCardozo on 5/30/19.
//  Copyright © 2019 NicolasCardozo. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void dfsUtil(vector<int> nodes[], int v, bool visited[]) {
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";
    
    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (auto u : nodes[v])
        if (!visited[u])
            dfsUtil(nodes, u, visited);
}

// DFS traversal of the vertices reachable from v.
void dfs(vector<int> nodes[], int v) {
    // Mark all the vertices as not visited
    bool *visited = new bool[nodes->size()];
    for (int i = 0; i < nodes->size(); i++) {
        visited[i] = false;
    }
    dfsUtil(nodes, v, visited);
}
