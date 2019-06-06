//
//  HashSuffixArray.cpp
//  Strings
//
//  Created by NicolasCardozo on 6/6/19.
//  Copyright © 2019 NicolasCardozo. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1 << 21;

typedef unsigned long long hsa;

const hsa BASE = 137; //hash

int N;
char * S;
int sa[MAXN];
hsa h[MAXN], hPow[MAXN];

#define getHash(lo, size) (h[lo] - h[(lo) + (size)] * hPow[size])

inline bool sufCmp(int i, int j) {
    int lo = 1, hi = min(N - i, N - j);
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (getHash(i, mid) == getHash(j, mid))
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return S[i + hi] < S[j + hi];
}

void buildSA() {
    N = strlen(S);
    hPow[0] = 1;
    for (int i = 1; i <= N; ++i)
        hPow[i] = hPow[i - 1] * BASE;
    h[N] = 0;
    for (int i = N - 1; i >= 0; --i)
        h[i] = h[i + 1] * BASE + S[i], sa[i] = i;
    
    stable_sort(sa, sa + N, sufCmp);
}
