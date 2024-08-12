#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[105];
ll dp[1000005];
const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, x; cin >> n >> x;
    for (ll i = 1; i <= n; i++) {
        cin >> A[i];
    }

    dp[0] = 1;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= x; j++) {
            if (j - A[i] < 0) continue;
            (dp[j] += dp[j-A[i]]) %= MOD;
        }
    }

    cout << dp[x] << "\n";
    
    return 0;
}