#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[200005], B[200005], C[200005], D[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll n, m; cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        for (int j = 1; j <= m; j++) {
            cin >> B[j];
        }

        sort(A+1, A+n+1);
        sort(B+1, B+m+1, greater<ll> ());

        for (ll i = 1; i <= n; i++) {
            C[i] = abs(A[i] - B[i]);
            if (i > 1) C[i] += C[i-1];
        }

        ll j = m;
        for (ll i = n; i >= 1; i--) {
            D[i] = abs(A[i] - B[j--]);
            if (i < n) D[i] += D[i+1];
        }

        D[n+1] = 0;
        ll ans = LLONG_MIN;
        for (int i = 0; i <= n; i++) {
            ans = max(ans, C[i]+D[i+1]);
        }
        cout << ans << "\n";
    }
    
    return 0;
}