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
        ll n; ll x; cin >> n >> x;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        int l = 1, r = 0;
        ll X = 0;
        vector<ll> dp(n+5);
        while (l <= n && r <= n) {
            while (X <= x && r+1 <= n) X += A[++r];
            
            while (X > x) {
                dp[r] += dp[l-1] + 1;
                X -= A[l++];
            }

            X += A[++r];
        }

        ll Y = 0;
        for (int i = 1; i <= n; i++) Y += dp[i];

        ll ans = n*(n-1)/2 + n - Y;
        cout << ans << "\n";
    }
    
    return 0;
}

/*
1
3 2
1 2 3
*/