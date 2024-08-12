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
        ll n, m; cin >> n >> m;
        priority_queue<ll> PQ;
        for (ll i = 1; i <= n; i++) {
            ll a; cin >> a;
            PQ.push(-a);
        }

        for (ll i = 1; i <= m; i++) {
            ll b; cin >> b;
            PQ.pop();
            PQ.push(-b);
        }
        ll res = 0;
        
        while (!PQ.empty()) {
            res -= PQ.top(); PQ.pop();
        }

        cout << res << "\n";
    }
    
    return 0;
}