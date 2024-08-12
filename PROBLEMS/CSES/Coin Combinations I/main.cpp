#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[105];
ll dp[1000005];
// const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, x; cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> A[i];
    
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= n; j++) {
            if (i - A[j] < 0) continue;
            (dp[i] += dp[i - A[j]]) %= 1000000007;
        }
    }

    cout << dp[x] << "\n";
    
    return 0;
}