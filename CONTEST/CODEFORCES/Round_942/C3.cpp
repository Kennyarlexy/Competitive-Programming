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
        ll n, k; cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            ll a; cin >> a;
            A[i] = {a, a};
        }

        sort(A+1, A+1+n);
        for (int i = 2; i <= n; i++) {
            A[i].se += A[i-1].se;
        }

        if (k >= n*A[n].fi - A[n].se) {
            ll x = A[n].fi;
            ll y = (k - (A[n].fi*n - A[n].se)) / n;
            ll z = k - (A[n].fi*n - A[n].se + y*n);
            ll ans = (x+y-1)*n + 1 + z;
            cout << ans << "\n";
        } else {
            int i;
            for (i = 2; i <= n; i++) {
                if (A[i].fi*i - A[i].se > k) break;
            }
            ll x = A[i-1].fi;
            ll y = (k - (A[i-1].fi*(i-1) - A[i-1].se)) / (i-1);
            ll z = k - (A[i-1].fi*(i-1) - A[i-1].se + y*(i-1));
            ll ans = (x+y-1)*n + 1 + z;
            cout << ans << "\n";
        }
    }
    
    return 0;
}