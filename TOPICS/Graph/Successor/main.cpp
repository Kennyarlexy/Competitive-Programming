#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

/*
    succ[i][j] means the 2^i-th successor of node j
*/
int succ[15][1005];
int f(int u, ll k) {
    while (k > 0) {
        ll i = __builtin_ctzll(k);
        u = succ[i][u];
        k ^= (1LL << i);
    }
    return u;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        succ[0][u] = v;
    }
    ll x = 64 - __builtin_clzll(1000LL) - 1;
    for (int i = 1; i <= x; i++) {
        for (int u = 1; u <= n; u++) {
            succ[i][u] = succ[i-1][succ[i-1][u]];
        }
    }

    int Q; cin >> Q;
    for (int q = 1; q <= Q; q++) {
        int u, k; cin >> u >> k;
        int ans = f(u, k);
        cout << ans << "\n";
    }
    
    return 0;
}

/*
9 9
1 3
9 3
3 7
7 1
2 5
5 2
6 2
4 6
8 6
5
1 1
2 2
3 4
4 8
9 8
*/