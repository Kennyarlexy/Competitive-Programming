#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll target, n;
ll A[1005];
pair<ll, ll> dp[1005]; //store {previous, min_moves}

ll dpf(ll T) {
    //returns min moves
    if (T == 0) return 0;
    if (T < 0 || dp[T].second == -2) return -2; //if dp[T].second = -2, it means that it's checked and 
    // impossible, noted with the moves of -2;
    if (dp[T].second != -1) return dp[T].second; //if checked

    for (ll i = 1; i <= n; i++) {
        ll rem = T - A[i];
        ll prevMoves = dpf(rem);
        if (prevMoves != -2) {
            if (prevMoves < dp[T].second || dp[T].second == -1) {
                dp[T].first = rem;
                dp[T].second = prevMoves + 1;
            }
        }
    }

    if (dp[T].second == -1) dp[T].second = -2;
    return dp[T].second;
}

int main() {
    fast_io();
    //use ll when possible!
    memset(dp, -1, sizeof(dp));
    cin >> target >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> A[i];
    }

    if (dpf(target) != -2) {
        cout << "YES\n" << dp[target].second << " moves\n";
        ll cur = target;
        while (dp[cur].first != -1) {
            cout << cur - dp[cur].first << " ";
            cur = dp[cur].first;
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}