#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll n; cin >> n;
        if (n == 2) {
            cout << "YES\n";
            cout << "1 -1\n";
        } else if (n == 3) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            ll a = n/2 - 1;
            ll b = 1 - (n+1)/2;
            for (ll i = 1; i <= n; i++) {
                if (i % 2 == 1) cout << a << " ";
                else cout << b << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}