#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second 
using namespace std;

ll C[] = {1, 3, 6, 10, 15};
ll dp[150500];
ll dpf(ll n) {
    if (n < 0) return 999999999999LL;
    if (n == 0) return 0;
    
    if (dp[n] != -1) return dp[n];

    ll mn = LLONG_MAX;
    for (int i = 0; i < 5; i++) {
        mn = min(mn, dpf(n-C[i]));
    }

    return dp[n] = mn+1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= 150000; i++) {
        dp[i] = dp[i-1]+1;
        for (int j = 1; j < 5; j++) {
            if (i - C[j] < 0) continue;
            dp[i] = min(dp[i], dp[i-C[j]] + 1); 
        }
    }

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll n; cin >> n;
        ll x = n / 150000;
        ll y = dp[n%150000];
        ll ans = x*10000 + y;
        cout << ans << "\n";
    }
    // cout << "OK\n";
    
    return 0;
}