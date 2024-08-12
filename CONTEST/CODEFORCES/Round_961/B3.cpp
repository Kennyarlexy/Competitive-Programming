#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

pair<ll, ll> A[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll n, m; cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> A[i].fi;
        for (int i = 1; i <= n; i++) cin >> A[i].se;



        ll mx = 0;
        for (int i = 1; i < n; i++) {
            ll _m = m;
            ll k = min(A[i].se, _m/A[i].fi);
            ll X = k*A[i].fi;
            _m -= X;
            if (i < n) {
                ll k2 = min(A[i+1].se, _m/A[i+1].fi);
                ll X2 = k2*A[i+1].fi;
                X += X2;
            }

            mx = max(mx, X);
        }
    }
    
    return 0;
}