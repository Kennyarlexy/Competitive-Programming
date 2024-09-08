#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

int A[400005];

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
                st[k][i] = st[k-1][i] & st[k-1][i+half];
            }
        }
    }

    int query(int l, int r) {
        int w = r-l+1;
        int k = __bit_width(w) - 1;
        
        if (__builtin_popcount(w) == 1) return st[k][l];

        int half = (1 << k);
        return st[k][l] & st[k][r-half+1];
    }
};

bool f(int X, int K) {
    return (X & K) == K;
}

// first true
bool g(int X, int K) {
    return (X | K) != K;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, K; cin >> n >> K;
    for (int i = 1; i <= n; i++) cin >> A[i];

    SparseTable st(n);
    ll cnt = 0;

    for (int i = 1; i <= n; i++) {
        int x = i;
        for (int step = n; step > 0; step /=2) {
            while (x + step <= n && f(st.query(i, x+step), K)) x += step;
        }

        if (st.query(i, x) == K) {
            if (A[i] == K) cnt += (x - i + 1);
            else {
                int y = i;
                for (int step = n; step > 0; step /= 2) {
                    while (y + step <= x && g(st.query(i, y+step), K)) y += step;
                }
                cnt += (x-y);
            }            
        }
    }

    cout << cnt << "\n";
        
    return 0;
}