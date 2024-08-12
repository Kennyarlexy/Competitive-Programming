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
        ll n, k; cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        sort(A+1, A+1+n, greater<ll>());

        ll x = A[n];

        int i = n-1;
        for ( ; i >= 1; i--) {
            ll m = n-i;

            ll dx = min(A[i] - A[i-1], k/m);            
            if (dx == 0) break;

            x += dx;
            k -= dx*m;
        }

        x += k/n;

        cout << x << "\n";

        ll ans = 0;
        if (x >= 1) ans += (x-1)*n + 1;    
        if (x > 0) ans += i;

        // cout << ans << "\n";

    }
    
    return 0;
}

/*
1
3 4
6 1 8
*/