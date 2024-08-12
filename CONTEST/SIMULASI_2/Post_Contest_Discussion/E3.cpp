#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll dp[5005][2];

int main() {
    fast_io();
    //use ll when possible!
    ll n, m; cin >> n >> m;
    
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (ll i = 2; i <= n; i++) {
        for (ll j = 0; j <= 1; j++) {
            // if (i <= m) {
            //     dp[i][j] = dp[i-1][j] + dp[i-1][!j];
            // } else {
            //     dp[i][j] = dp[i-1][j] + dp[i-1][!j] - dp[i-m-1][j];
            // }

            // if (i <= m) {
            //     dp[i][j] = dp[i-1][j] + dp[i-1][j&1];
            // } else {
            //     dp[i][j] = dp[i-1][j] + dp[i-1][j&1] - dp[i-m-1][j];
            // }

            // if (i <= m) {
            //     dp[i][j] = dp[i-1][0] + dp[i-1][1];
            // } else {
            //     dp[i][j] = dp[i-1][0] + dp[i-1][1] - dp[i-m-1][(j+1)%2];
            // }

            // if (i <= m) {
            //     dp[i][j] = dp[i-1][j] + dp[i-1][(j+1)%2];
            // } else {
            //     dp[i][j] = dp[i-1][j] + dp[i-1][(j+1)%2] - dp[i-m-1][(j+1)%2];
            // }




            if (i <= m) {
                dp[i][j] = dp[i-1][0] + dp[i-1][1];
            } else {
                dp[i][j] = dp[i-m+1][j]*dp[m-1][j]*2;
            }
        }
    }

    cout << dp[n][0] + dp[n][1] << "\n";

    return 0;
}