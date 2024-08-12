#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[1005];

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll n; cin >> n;
        for (ll i = 0; i < n; i++) {
            cin >> A[i];
        }
        ll _max = 0;
        for (ll i = 0; i < n; i++) {
            _max |= A[i];
        }

        ll _min = (1LL << 11) - 1;
        for (ll i = 0; i < n; i++) {
            _min &= A[i];
        }

        cout << _max - _min << "\n";
    }

    return 0;
}