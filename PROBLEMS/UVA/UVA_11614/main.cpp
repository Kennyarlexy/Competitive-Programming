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
        ll N; cin >> N;

        ll row = 0;
        for (ll s = 1e18; s >= 1; s/=2) {
            ll n = row+s;
            ll check = n*(1+n); //Sn * 2
            while (!__builtin_smulll_overflow(n, 1+n, &check) && check <= 2*N) {
                row += s;
                n = row + s;
                check = n*(1+n);
            }
        }

        cout << row << "\n";
    }

    return 0;
}