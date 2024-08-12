#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll v, w, x, y, z;
        cin >> v >> w >> x >> y >> z;
        ll a = v;
        // ll a = v + 100000000000000000LL;
        ll e = a + z;
        ll d = e + y;
        ll c = d + x;
        ll b = c + w;
        cout << a << " " << b << " " << c << " " << d << " " << e << "\n";
        // cout << a % b << "\n";
        // cout << b % c << "\n";
        // cout << c % d << "\n";
        // cout << d % e << "\n";
        // cout << e % a << "\n";
    }

    return 0;
}