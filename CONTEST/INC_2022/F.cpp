#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll D[200005];

int main() {
    fast_io();
    //use ll when possible!
    ll N, P0, X; cin >> N >> P0 >> X;
    for (ll i = 0; i < N; i++) {
        cin >> D[i];
    }    

    for (ll i = 1; i < N; i++) {
        D[i] += D[i-1];
    }

    ll res = P0;
    for (ll h = 1; h <= N; h++) {
        ll loop = (X-P0-D[h-1])/D[N-1];
        // ll loop = (min(X, P0)-max(X, P0)-D[h-1])/D[N-1];
        // cout << "loop = " << loop << "\n";
        if (loop < 0) continue;
        ll P_min = P0 + loop * D[N-1] + D[h-1]; 
        // cout << "P_min = " << P_min << "\n";
        if (P_min >= X) {
            if (res < X) res = P_min;
            else res = min(res, P_min);
        }
    }
    if (res < X) cout << "-1\n";
    else cout << res << "\n";

    return 0;
}