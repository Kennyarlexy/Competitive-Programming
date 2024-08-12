#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
#define LSOne(x) ((x) & (-x))
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll a, b, r; cin >> a >> b >> r;

        ll y = a ^ b;
        while (y > 0 && r >= LSOne(y)) {
            ll mn = abs(a - b), mn_x = LLONG_MAX;
            bool f = false;

            for (ll i = 0; i < 64; i++) {
                ll x = (1LL << i);
                if (x > r) break;

                if (x & y) {
                    ll ta = a ^ x;
                    ll tb = b ^ x;
                    ll d = abs(ta - tb);
                    if (d < mn) {
                        f = true;
                        mn = d;
                        mn_x = x;
                    } 
                }
            }
            
            if (!f) break;
            y ^= mn_x;
            r ^= mn_x;
            a ^= mn_x;
            b ^= mn_x;
        }

        ll ans = abs(a-b);
        cout << ans << "\n";        
    }
    
    return 0;
}