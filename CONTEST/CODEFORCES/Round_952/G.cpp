#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

const ll MOD = 1e9 + 7;

ll f(ll x, ll k) {
    if (k == 0) return 1;
    ll y = f(x, k/2);
    ll z = y*y % MOD;
    if (k % 2 == 1) z = z * x % MOD;
    
    return z;
}

ll g(ll a, ll r, ll n) {
    ll Sn = a * (f(r, n) - 1) % MOD * f(r-1, MOD - 2) % MOD;

    return Sn;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll l, r, k; cin >> l >> r >> k;
        
        ll a = 10 / k;
        if (a * k >= 10) a--;

        ll X = f(a+1, l) * a % MOD;
        ll Y = g(X, a + 1, r-l);

        cout << Y << "\n";
    }
    
    return 0;
}