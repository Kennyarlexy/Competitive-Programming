#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[55];
ll N;
ll dp[55][55];

// l is the l-th part, r is the r-th part
ll dpf(ll l, ll r) {
    if (r - l == 1) return 0;
    if (dp[l][r] != -1) return dp[l][r];

    ll minn = LONG_LONG_MAX;
    for (ll m = l+1; m < r; m++) {
        minn = min(minn, dpf(l, m) + dpf(m, r));
    }

    return dp[l][r] = minn + A[r] - A[l];
}

int main() {
    fast_io();
    //use ll when possible!
    ll L;
    while (true) {
        cin >> L;
        if (L == 0) break;
        memset(dp, -1, sizeof(dp));
        cin >> N;
        for (ll i = 1; i <= N; i++) {
            cin >> A[i];
        }
        A[N+1] = L;
        ll res = dpf(0, N+1);
        cout << "The minimum cutting is " << res << ".\n";
    }

    return 0;
}