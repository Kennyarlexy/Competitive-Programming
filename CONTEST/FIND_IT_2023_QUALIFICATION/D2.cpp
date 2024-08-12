#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll m = 1;

ll calcMove(ll dist) {
    ll move = 0;
    ll n = 0;
    for (ll i = m; i*i <= dist; i++) {
        if (dist % (i*i) == 0) {
            n = i;
            move++;
        }
    }
    if (n == 0) return dist;
    else {
        m = n;
        return move + (dist/n);
    }
}

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll x, y; cin >> x >> y;
        cout << calcMove(x) + calcMove(y) << "\n";
    }

    return 0;
}