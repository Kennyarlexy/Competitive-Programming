#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[100];

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t  = 1; t <= T; t++) {
        ll n; cin >> n;
        for (ll i = 0; i < n; i++) {
            cin >> A[i];
        }

        bool OK = true;
        ll _max = 0;
        for (ll i = n-1; i > 0; i--) {
            if (A[i] < A[i-1]) {
                OK = false;
                _max = max(_max, A[i-1]);
            }
        }

        if (OK) cout << 0 << "\n";
        else cout << _max << "\n";
    }

    return 0;
}