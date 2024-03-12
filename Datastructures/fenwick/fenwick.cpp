#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <fstream>
#include <sstream>
#include <random>


using namespace std;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()){
        for (int i = 0; i < n; i++) {
            bit[i] += a[i];
            int r = i | (i + 1);
            if (r < n) bit[r] += bit[i];
        }
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
    
    void update(int n, int index, int val) {
        while (index <= n) {
            bit[index] += val;
            index += index & (-index);
        }
    }
};


int g(int n) {
    return n & (n+1);
}

int h(int j) {
    return j | (j+1);
}

int main() {
     vector<int> arr;
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(7);
    arr.push_back(2);
    arr.push_back(8);
    arr.push_back(7);
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(5);
    FenwickTree ft = FenwickTree(arr);
    int res = ft.sum(2, 7);
    cout << res << endl;
    ft.update(arr.size(), 2, 13);
    res = ft.sum(2, 7);
    cout << res << endl;
    
    return 0;
}
