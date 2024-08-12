#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll n, m; 
ll dp[5005][5005];

ll dpf(ll l, ll r) {
    if (l > m) return 0;
    if (r == 0) return 1;
    if (dp[l][r] != -1) return dp[l][r];

    dp[l][r] = (dpf(l+1, r-1) + dpf(1, r-1)) % 1000000007;
    return dp[l][r];
}

int main() {
    fast_io();
    //use ll when possible!
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    ll res = (dpf(1, n-1)*2) % 1000000007;
    cout << res << "\n";

    return 0;
}