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
        ll a, b, l; cin >> a >> b >> l;
        ll A = 1;
        set<ll> ans;
        for (ll x = 1; ; x++) {
            if (A > l) break;
            ll B = 1;
            for (ll y = 1; ; y++) {
                ll X = A*B;
                if (X > l) break;
                if (l % X == 0) ans.insert(l / X);
                B *= b;
            }
            A *= a;
        }
        ll m = ans.size();
        cout << m << "\n";
    }
    
    return 0;
}