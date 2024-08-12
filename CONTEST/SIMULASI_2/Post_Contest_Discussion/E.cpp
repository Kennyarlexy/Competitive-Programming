#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll C(ll X, ll Y) {
    ll res = 1;
    ll Z = X-Y;
    if (Z < Y) swap(Y, Z);
    for (ll a = X; a > Z; a--) {
        res *= a;
        while (Y > 1 && res % Y == 0) {
            res /= Y;
            Y--;
        }
        res = res % 1000000007;
    }
    return res;
}

int main() {
    fast_io();
    //use ll when possible!
    ll n, m; cin >> n >> m;

    ll res = 2;
    for (ll SL = 2; SL <= m; SL++) {
        ll F = n / SL;
        for (ll f = 1; f <= F; f++) {
            ll AL = n - f*(SL-1);
            res += 2*C(AL, f);
            res = res % 1000000007;
        }
    }

    cout << res << "\n";

    return 0;
}