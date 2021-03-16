//
//  uva11362.cpp
//  Strings
//
//  Created by NicolasCardozo on 6/4/19.
//  Copyright © 2019 NicolasCardozo. All rights reserved.
//

#include <bits/stdc++.h>

#define A 10
#define MAX 10010
using namespace std;

typedef pair<int, bool> pib;

pib trie[MAX][A];
int following = 1;

bool buildTrie(string s) {
    int i=0, v=0;
    while(i<s.size()) {
        if(i == 0) {
            if(trie[v][s[i]-48].second) {
                return false;
            }
        } else {
            if(trie[v][s[i-1]-48].second) {
                return false;
            }
        }
        if(trie[v][s[i]-48].first == -1) {
            v = trie[v][s[i++]-48].first = following++;
        } else {
            v = trie[v][s[i++]-48].first;
        }
    }
    trie[v][s[i-1]-48].second = true;
    return true;
}

void cleanTrie() {
    for(int i=0; i<MAX; i++)
        for(int j=0; j<A; j++) {
            trie[i][j].first=-1;
            trie[i][j].second=false;
        }
}

int main() {
    int t;
    bool ans;
    string n;
    cin >> t;
    for(int i=0; i<t; i++) {
        cleanTrie();
        int numbers;
        cin >> numbers;
        ans = true;
        for(int j=0; j<numbers; j++) {
            cin >> n;
            ans = buildTrie(n);
            if(!ans) {
                cout << "NO\n";
                break;
            }
        }
        if(ans)
            cout << "YES\n";
    }
    return 0;
}
