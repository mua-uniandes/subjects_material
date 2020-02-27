//
//  kmp.cpp
//  Strings
//
//  Created by NicolasCardozo on 2/27/20.
//

#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100010
char T[MAX_N], P[MAX_N]; // T = text, P = pattern
int b[MAX_N], t_len, p_len; // b = back table


void kmpPreprocess() { // call this before calling kmpSearch()
    int i = 0, j = -1; b[0] = -1; // starting values
    while (i < p_len) { // pre-process the pattern string P
        while (j >= 0 && P[i] != P[j])
            j = b[j]; // different, reset j using b
        i++; j++;
        b[i] = j;
    }
}

void kmpSearch() {
    int i = 0, j = 0; // starting values
    while (i < t_len) { // search through string T
        while (j >= 0 && T[i] != P[j])
            j = b[j]; // different, reset j using b
        i++; j++;
        if (j == p_len) { // a match found
            printf("P is found at index %d in T\n", i - j);
            j = b[j]; // prepare j for the next possible match
        }
    }
}

int main() {
    //fill T and P
    kmpPreprocess();
    kmpSearch();
    return 0;
}
