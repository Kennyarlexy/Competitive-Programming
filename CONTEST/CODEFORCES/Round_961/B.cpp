#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

// ll A[200005], B[200005];
pair<ll, ll> A[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll n, m; cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            ll x; cin >> x;
            A[i] = {x, x};
        }

        sort(A+1, A+1+n);
        for (int i = 2; i <= n; i++) {
            A[i].fi += A[i-1].fi;
        }

        // ll mx = LLONG_MIN;
        ll mx = 0;
        for (int i = 1; i <= n; i++) {
            if (A[i].se > m) continue;
            ll x = i;
            for (ll step = n; step > 0; step /= 2) {
                while (x + step <= n && A[x+step].fi - A[i-1].fi <= m && A[x+step].se - A[i].se <= 1) x += step;
            }
            mx = max(mx, A[x].fi - A[i-1].fi);
        }

        cout << mx << "\n";
    }
    
    return 0;
}