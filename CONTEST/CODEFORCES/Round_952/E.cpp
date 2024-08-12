#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll x, y, z, k; cin >> x >> y >> z >> k;
        ll mx = 0;
        for (ll i = 1; i <= x; i++) {
            for (ll j = 1; j <= y; j++) {
                if (k % (i*j) != 0) continue;

                ll h = k / (i*j);
                if (h > z) continue;
                
                ll a = x - i + 1;
                ll b = y - j + 1;
                ll c = z - h + 1;
                mx = max(mx, a*b*c);
            }
        }

        cout << mx << "\n";
    }
    
    return 0;
}