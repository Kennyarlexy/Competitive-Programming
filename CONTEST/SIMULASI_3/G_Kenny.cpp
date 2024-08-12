#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll modexp(ll X, ll exp, ll mod = 1000000007) {
    if (exp == 0) return 1;
    
    ll temp = modexp(X, exp/2, mod);
    ll res = (temp * temp) % mod;
    if (exp % 2 == 1) res = (res * X) % mod;

    return res;
}

int main() {
    fast_io();
    //use ll when possible!
    ll n; cin >> n;
    ll cur = 0;
    for (ll i = 1; i <= n; i++) {
        cur = modexp(i, cur);
    }

    //X^n % m == X^(phi(m)

    cout << cur << "\n";

    return 0;
}