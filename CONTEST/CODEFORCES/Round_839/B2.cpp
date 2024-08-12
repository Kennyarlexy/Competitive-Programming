#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        bool OK = false;
        for (ll i = 1; i <= 4; i++) {
            if (a < b && c < d && a < c && b < d) {
                OK = true;
                break;
            }
            ll ta = a, tb = b, tc = c, td = d;
            a = tc;
            b = ta;
            c = td;
            d = tb;
        }
        if (OK) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}