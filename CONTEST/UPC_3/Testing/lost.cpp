#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll q, w, e, r, t, y, u;
    cin >> q >> w >> e >> r >> t >> y >> u;
    ll n; cin >> n;

    ll used = 0;
    for (ll i = 1; i <= n; i++) {
        ll m; cin >> m;
        used += m;
    }
    
    ll has = q*100000 + w*50000 + e*20000 + r*10000 + t*5000 + y*2000 + u*1000;
    ll lost = has - used;
    if (lost < 0) cout << "-1\n";
    else cout << lost << "\n";

    
    return 0;
}