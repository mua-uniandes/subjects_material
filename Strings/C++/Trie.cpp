//
//  Trie.cpp
//  Strings
//
//  Created by NicolasCardozo on 6/4/19.
//  Copyright © 2019 NicolasCardozo. All rights reserved.
//

#include <bits/stdc++.h>

#define A 26
#define MAX 7
using namespace std;

int trie[MAX][A];
int following = 1;

void buildTrie(string s) {
    int i=0, v=0;
    while(i<s.size()) {
        if(trie[v][s[i]-65] == -1) {
            v = trie[v][s[i++]-65] = following++;
        } else {
            v = trie[v][s[i++]-65];
        }
    }
}

int main() {
    int n;
    cin >> n;
    memset(trie, -1, A*MAX*sizeof(int));
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        buildTrie(s);
    }
    return 0;
}
