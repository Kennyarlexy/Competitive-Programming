#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[200005];

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll N; cin >> N;
        for (ll i = 1; i <= N; i++) {
            cin >> A[i];
        }

        ll x_high = 1e9;
        ll x_low = 0;
        bool OK = true;
        for (ll i = 1; i < N; i++) {
            if (A[i] < A[i+1]) {
                x_high = min(x_high, (A[i] + A[i+1]) / 2);
            } else if (A[i] > A[i+1]) {
                x_low = max(x_low, (A[i] + A[i+1] + 1) / 2);
            }
            if (x_low > x_high) {
                OK = false;
                break;
            }
        }

        if (OK) cout << x_low << "\n";
        else cout << "-1\n";
    }

    return 0;
}