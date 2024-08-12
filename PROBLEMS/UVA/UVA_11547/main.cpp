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
        ll res = (n*63 + 7492) * 235 / 47 - 498;
        cout << abs((res % 100) / 10) << "\n";
    }

    return 0;
}