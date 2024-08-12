#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll dp[50][50];

int main() {
    fast_io();
    //use ll when possible!
    ll n, m; cin >> n >> m;
    for (ll r = 1; r <= n; r++) {
        dp[r][1] = 1;
    }

    for (ll c = 1; c <= m; c++) {
        dp[1][c] = 1;
    }

    for (ll r = 2; r <= n; r++) {
        for (ll c = 2; c <= m; c++) {
            dp[r][c] = dp[r-1][c] + dp[r][c-1];
        }
    }

    cout << dp[n][m] << "\n";

    return 0;
}