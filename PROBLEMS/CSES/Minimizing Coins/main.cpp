#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[105];
ll dp[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, x; cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= x; i++) {
        dp[i] = -1;
        for (int j = 1; j <= n; j++) {
            if (i - A[j] < 0) continue;
            if (dp[i - A[j]] == -1) continue;

            dp[i] = (dp[i] == -1) ? dp[i-A[j]] + 1 : min(dp[i], dp[i-A[j]] + 1);
        }
    }

    ll ans = dp[x];
    cout << ans << "\n";
    
    return 0;
}