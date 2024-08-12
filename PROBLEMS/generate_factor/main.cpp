#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}


ll f(ll x) {
    ll n = 1;
    for (ll i = 2; i*i <= x; i++) {
        ll exp = 1;
        while (x % i == 0) {
            exp++;
            x /= i;
        }

        n *= exp;
    }

    if (x > 1) n *= 2;

    return n;
}

int main() {
    fast_io();
    //use ll when possible!
    while (true) {
        ll x; cin >> x;
        if (x == 0) break;
        if (f(x) % 2 == 0) cout << "no\n";
        else cout << "yes\n";
    }
    
    return 0;
}