#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;

ll f(ll n, ll k) {
    if (k == 0) return 1;
    ll x = f(n, k/2);
    ll y = x*x % MOD;
    if (k % 2 == 1) y = (y*n) % MOD;

    return y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    ll ans = f(2, n) - 1;
    cout << ans << "\n";
    
    return 0;
}