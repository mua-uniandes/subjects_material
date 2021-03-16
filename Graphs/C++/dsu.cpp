//
//  dsu.cpp
//  Graphs
//
//  Created by NicolasCardozo on 16/03/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

vector<int> parent(n); 
void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}


