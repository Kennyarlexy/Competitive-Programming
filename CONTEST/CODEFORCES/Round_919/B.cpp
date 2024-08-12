#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, k, x; cin >> n >> k >> x;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            // B[i] = A[i];
        }

        sort(A+1, A+n+1, greater<ll> ());
        // sort(B+1, B+n+1, greater<ll> ());

        for (int i = n-1; i >= 1; i--) {
            A[i] += A[i+1];
        }

        ll ans = LLONG_MIN;
        for (int i = 1; i <= min(n, k+1); i++) {
            ll X = A[i];
            ll Y = A[i];
            if (i+x <= n) Y -= A[i+x];
            ll sum = X - 2*Y;

            ans = max(ans, sum);
        }

        if (k == n) ans = max(ans, 0LL);

        cout << ans << "\n";
    }
    
    return 0;
}