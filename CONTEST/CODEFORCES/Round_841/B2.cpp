#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
ull mod = 1e9 + 7;

ull f(ull n) {
    return 1011*(n*n%mod + n) % mod;
}

ull g(ull n) {
    return 337*n%mod * (n+1)%mod * (2*n+1)%mod;
}

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ull n; cin >> n;
        ull A = g(n);
        ull B = g(n-1) + f(n-1);

        cout << (A + B) % mod << "\n";
    }    

    return 0;
}