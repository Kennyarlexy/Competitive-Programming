#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second 
using namespace std;

ll A[200005], B[200005];

ll sum(ll i, ll j) {
    return B[j] - B[i-1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll n, m; cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        for (int i = 1; i <= n; i++) {
            cin >> B[i];
        }

        ll x = 0;
        for (int i = n; i > m; i--) {
            x += min(A[i], B[i]);
        }

        for (int i = 2; i <= m; i++) {
            B[i] += B[i-1];
        }

        ll mn = LLONG_MAX;
        for (int i = 1; i <= m; i++) {
            ll y = A[i];
            if (i+1 <= m) y += sum(i+1, m);
            mn = min(mn, y);
        }

        ll ans = x + mn;
        cout << ans << "\n";
    }
    
    return 0;
}