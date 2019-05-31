//
//  codeforces217A.cpp
//  Graphs
//
//  Created by Pietro Ehrlich on 5/30/19.
//

#include <bits/stdc++.h>

using namespace std;

#define MAX 110
typedef pair<int, int> pii;

int n;
int par[MAX];
pii coord[MAX];

int findPar(int x){
    return (par[x] < 0 ? x : (par[x] = findPar(par[x])));
}

void merge(int a , int b){
    a = findPar(a); b = findPar(b);
    if(a == b) return;
    
    if(par[a] > par[b])
        swap(a , b);
    
    par[a] += par[b];
    par[b] = a;
}

int main() {

    cin >> n;
    
    for(int i=0; i< n; i++) {
        int x, y;
        cin >> x >> y;
        coord[i] = {x , y};
    }
    
    memset(par , -1 , sizeof(par));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if(coord[i].first == coord[j].first
            or coord[i].second == coord[j].second)
                merge(i , j);
        }
        
        unordered_set<int> ans;
        
        int x;
        for(int i = 0 ; i < n ; ++i){
            x = findPar(i);
            if(ans.find(x) == ans.end())
                ans.insert(x);
        }
        
        cout << ans.size() - 1 << '\n';
    }
    
    return 0;
}
