#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll modexp(ll X, ll exp, ll mod = 1000000007) {
    if (exp == 0) return 1;

    ll root = modexp(X, exp/2);
    ll res = (root*root) % mod;
    if (exp % 2 == 1) res = (res*X) % mod;
    return res;
}

int main() {
    fast_io();
    //use ll when possible!
    ll X; cin >> X;
    ll res = modexp(2, X) - 1;
    cout << res << "\n";

    return 0;
}