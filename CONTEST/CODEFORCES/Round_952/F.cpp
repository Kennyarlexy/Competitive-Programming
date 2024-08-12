#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

ll A[200005], C[200005];

ll f(ll k, ll n) {
    ll dmg = 0;
    for (int i = 1; i <= n; i++) {
        dmg += (k + C[i] - 1) / C[i] * A[i];
        if (dmg < 0) return LLONG_MAX; // overflow
    }

    return dmg;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll h, n; cin >> h >> n;
        for (int i = 1; i <= n; i++) cin >> A[i];
        for (int i = 1; i <= n; i++) cin >> C[i];


        ll x = 1e12;
        for (ll step = x; step > 0; step /= 2) {
            while (x - step > 0 && f(x - step, n) >= h) x -= step;
        }

        cout << x << "\n";
    }
    
    return 0;
}