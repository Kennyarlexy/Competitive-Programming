#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[1005][1005];
ll sum_r[1005];
ll sum_c[1005];

int main() {
    fast_io();
    //use ll when possible!
    ll n, m; cin >> n >> m;
    for (ll r = 1; r <= n; r++) {
        for (ll c = 1; c <= m; c++) {
            cin >> A[r][c];
        }
    }

    for (ll r = 1; r <= n; r++) {
        for (ll c = 1; c <= m; c++) {
            sum_r[r] += A[r][c];
        }
    }

    for (ll c = 1; c <= m; c++) {
        for (ll r = 1; r <= n; r++) {
            sum_c[c] += A[r][c];
        }
    }

    ll res = LONG_LONG_MIN;
    for (ll r = 1; r <= n; r++) {
        for (ll c = 1; c <= m; c++) {
            res = max(res, sum_r[r] + sum_c[c] - 2*A[r][c]);
        }
    }

    if (res < 0) cout << "0\n";
    else cout << res << "\n";

    return 0;
}

/*
3 3
-1 0 -1
0 -1 0
-1 0 -1 
*/