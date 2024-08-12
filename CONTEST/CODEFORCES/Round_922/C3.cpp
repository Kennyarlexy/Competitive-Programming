#include <bits/stdc++.h>
#define ll unsigned long long
#define fi first 
#define se second
// #define LSOne(x) ((x) & (-x))
using namespace std;

ll diff(ll a, ll b) {
    return max(a, b) - min(a, b);
}

ll LSOne(ll y) {
    if (y == 0) return 0;
    ll x = (1ULL << __builtin_ctzll(y));
    return x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll a, b, r; cin >> a >> b >> r;

        ll y = a ^ b;
        // cout << y << "\n";
        // cout << LSOne(y) << "\n";
        while (y > 0 && r >= LSOne(y)) {
            ll mn = diff(a, b), mn_x = ULLONG_MAX;

            for (ll i = 0; i < 64; i++) {
                ll x = (1ULL << i);
                if (x > r) break;

                if (x & y) {
                    ll ta = a ^ x;
                    ll tb = b ^ x;
                    ll d = diff(ta, tb);
                    if (d < mn) {
                        mn = d;
                        mn_x = x;
                    } 
                }
            }

            y -= mn_x;
            r -= mn_x;
            a ^= mn_x;
            b ^= mn_x;
        }

        ll ans = diff(a, b);
        cout << ans << "\n";        
    }
    
    return 0;
}