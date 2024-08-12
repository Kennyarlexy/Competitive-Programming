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
        ll k, n; cin >> k >> n;
        ll x = 1;
        ll dx = 0;

        ll i = 1;
        while (x + dx <= n-k+i && i <= k) {
            x += dx;
            cout << x << " ";
            dx++;
            i++;
        }

        while (i <= k) {
            cout << ++x << " ";
            i++;
        }
        cout << "\n";
    }

    return 0;
}