//not done

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[1005];
ll dp[1005][1005];

int main() {
    fast_io();
    //use ll when possible!
    memset(dp, -1, sizeof(dp)); //-1 in the dp table means there is no previous (impossible)
    ll target, n; cin >> target >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> A[i];
    }

    if (target == 0) {
        cout << "YES\n";
        return 0;
    }

    for (ll i = 1; i <= n; i++) {
        dp[1][A[i]] = 0;
    }

    for (ll i = 2; i <= target; i++) {
        for (ll j = 1; j <= target; j++) {
            if (dp[i-1][j] == -1) continue;
            for (ll k = 1; k <= n; k++) {
                dp[i][j+A[k]] = j;
            }
        }
        if (dp[i][target] != -1) {
            ll cur = target;
            while (cur != 0) {
                cout << cur - dp[i][cur] << " ";
                cur = dp[i][cur];
            }
            cout << "\n";
        }
    }

    return 0;
}