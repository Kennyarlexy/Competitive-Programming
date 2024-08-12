/* 
    try to make a sum equal to target using elements in N. all elements in N can be used multiple times

    Note:
    - It's better to use top-down DP for this kind of problem since we don't actually need to check all states
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

bool dp[1005][1005];
ll N[15];

int main() {
    fast_io();
    //use ll when possible!
    ll target, n; cin >> target >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> N[i];
    }

    if (target == 0) {
        cout << "YES\n";
        return 0;
    }

    dp[0][0] = true;
    bool OK = false;
    for (ll i = 1; i <= target; i++) {
        for (ll j = 0; j <= target; j++) {
            if (!dp[i-1][j]) continue;
            dp[i][j] = true;
            for (ll k = 1; k <= n; k++) {
                dp[i][j+N[k]] = true;
            }
        }

        if (dp[i][target]) {
            OK = true;
            break;
        }
    }

    cout << (OK ? "YES" : "NO") << "\n";

    return 0;
}