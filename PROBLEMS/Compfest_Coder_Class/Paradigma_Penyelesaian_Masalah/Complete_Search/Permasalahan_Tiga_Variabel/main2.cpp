#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[200005][5];

ll C(ll n, ll k) {
    if (n == k || k == 0) return 1;
    if (n < k) return 0;
    if (dp[n][k] != -1) return dp[n][k];
    
    // cout << "n = " << n << "   k = " << k << "\n";
    
    return dp[n][k] = C(n-1, k-1) + C(n-1, k);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N; cin >> N;
    memset(dp, -1, sizeof(dp));

    ll ans = C(N+2, 2);
    cout << ans << "\n";
    
    return 0;
}