#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> A = {0, 1, 4, 2, 5, 10, 3, 5, 6, 4, 9}; // 0 not used, 1 indexed
struct SparseTable {
    int max_k;
    int n;
    vector<vector<int>> st;

    SparseTable(int n) {
        this->n = n;
        max_k = __bit_width(n) - 1;
        st = vector<vector<int>> (max_k+1);

        build();
    }

    void build() {
        st[0].resize(n+1);
        for (int i = 1; i <= n; i++) st[0][i] = A[i];
        
        for (int k = 1; k <= max_k; k++) {
            int w = (1 << k);
            st[k].resize(n-w+2);
            int half = w/2;
            
            for (int i = 1; i+w-1 <= n; i++) {
                st[k][i] = min(st[k-1][i], st[k-1][i+half]);
            }
        }
    }

    int query(int l, int r) {
        int w = r-l+1;
        int k = __bit_width(w) - 1;
        
        if (__builtin_popcount(w) == 1) return st[k][l];

        int half = (1 << k);
        return min(st[k][l], st[k][r-half+1]);
    }
};