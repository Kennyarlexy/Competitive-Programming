#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[200010];

const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    dp[n] = dp[n-1] = 1;
    for (int i = n-2; i >= 1; i--) {
        dp[i] = (dp[i+2] + 2*dp[i+3] + dp[i+4]) % MOD;
    }
    ll ans = (dp[1] + dp[2] + dp[3]) % MOD;
    cout << ans << "\n";
    
    return 0;
}