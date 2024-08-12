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
        ll l, w, h; cin >> l >> w >> h;
        cout << "Case " << t << ": " << (l <= 20 && w <= 20 && h <= 20 ? "good" : "bad") << "\n";
    }

    return 0;
}