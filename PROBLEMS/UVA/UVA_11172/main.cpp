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
        ll a, b; cin >> a >> b;
        if (a > b) cout << ">\n";
        else if (a == b) cout << "=\n";
        else  cout << "<\n";
    }

    return 0;
}