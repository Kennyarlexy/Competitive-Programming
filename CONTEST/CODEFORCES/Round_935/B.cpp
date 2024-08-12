#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second 
using namespace std;

ll f(ll x, ll y, ll m) {
    ll k = y-x+1;
    ll N = (m+1 + x-1)/x + (m+1-k + y-1) / y;
    return N;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll a, b, m; cin >> a >> b >> m;
        if (a > b) swap(a, b);

        ll y = b;
        ll x = b - (b%a);

        // ll ans = max(f(x, y, m), f(y, x+a, m));
        ll ans = (m+1 + a-1) / a + (m+1 + b-1) / b;
        cout << ans << "\n";
    }
    
    return 0;
}