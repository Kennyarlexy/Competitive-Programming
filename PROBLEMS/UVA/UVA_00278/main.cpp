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
        char type; ll R, C;
        cin >> type >> R >> C;
        if (type == 'r') {
            cout << min(R, C) << "\n";
        } else if (type == 'k') {
            cout << C * (R/2) + ((C+1)/2 * (R%2)) << "\n";
        } else if (type == 'Q') {
            // we don't need below's code since m >= 4 and n >= 4
            // ll n = min(R, C);
            // if (n == 1) cout << "1\n";
            // else if (n <= 3) cout << n-1 << "\n";
            // else cout << n << "\n"; 
            cout << min(R, C) << "\n";
        } else {
            // if you don't add brackets, below will give WA
            cout << ((R+1)/2) * ((C+1)/2) << "\n";
        }
    }

    return 0;
}

