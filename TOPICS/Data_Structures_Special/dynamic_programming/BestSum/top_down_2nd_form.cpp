#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll target, n;
ll A[1005];
pair<ll, ll> dp[1005]; //store previous

bool dpf(ll T) {
    if (T < 0 || dp[T].first == -2) return false;
    if (T == 0) {
        dp[T].second = 0;
        return true;
    }
    if (dp[T].first != -1) return true;

    ll min = LONG_LONG_MAX; //no possible solution to construct every rem initially, so min moves = -1
    for (ll i = 1; i <= n; i++) {
        ll rem = T - A[i];
        if (dpf(rem)) {
            if (dp[rem].second < min) {
                min = dp[rem].second;
                dp[T].first = rem;
                dp[T].second = dp[rem].second + 1;
            }
        }
    }

    if (min == -1) {
        dp[T].first = -2;
        return false;
    }

    return true;
}

int main() {
    fast_io();
    //use ll when possible!
    memset(dp, -1, sizeof(dp));
    cin >> target >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> A[i];
    }

    if (dpf(target) != -1) {
        cout << "YES\n";
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