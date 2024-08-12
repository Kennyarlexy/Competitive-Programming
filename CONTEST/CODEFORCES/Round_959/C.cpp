#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

ll A[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; ll x; cin >> n >> x;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        int l = 1, r = 0;
        ll X = 0;
        vector<ll> dp(n+5);
        dp[0] = 1;
        while (l <= n && r <= n) {
            while (X <= x && r+1 <= n) {
                // cout << "entered\n";
                X += A[++r];
            }
            
            assert(X > x);            
            dp[r] += dp[l-1];
// cout << "l = " << l << "   r = " << r << " -> " << X << " > " << x << "\n";
            while (X - A[l] > x) {
                X -= A[l];
                l++;
// cout << "l = " << l << "   r = " << r << " -> " << X << " > " << x << "\n";
                dp[r] += dp[l-1];
            }

            X += A[++r];
        }

        ll Y = 0;
        for (int i = 1; i <= n; i++) {
// cout << dp[i] << "\n";
            Y += dp[i];
        }

        // ll ans = n*(n-1)/2 + n - dp[n];
        ll ans = n*(n-1)/2 + n - Y;
        cout << ans << "\n";
        // cout << "dp[n] = " << dp[n] << "\n";
    }
    
    return 0;
}

/*
1
3 2
1 2 3
*/