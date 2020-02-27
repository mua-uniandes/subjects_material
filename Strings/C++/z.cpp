//
//  z.cpp
//  Strings
//
//  Created by NicolasCardozo on 2/27/20.
//

#include <bits/stdc++.h>

using namespace std;

int x, l;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, x = 0, y = 0; i < n; ++i) {
        if (i <= y)
            z[i] = min (y - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > y)
            x = i, y = i + z[i] - 1;
    }
    return z;
}

int main() {
    string s; //get s
    z_function(s);
    return 0;
}
