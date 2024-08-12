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
    return ((n*n - n) / 2) % mod;
}

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ull n; cin >> n;        
        ull A = n;
        A = (A*(n+1))%mod;
        A = (A*((2*n+1)))%mod;
        A = (A*337) % mod;

        ull X = (n-1);
        X = (X*((n-1)+1))%mod;
        X = (X*((2*(n-1)+1)))%mod;
        X = (X*337) % mod;
        ull Y = (f(n-1)*2022) % mod;

        ull B = (X+Y) % mod;
        cout << (A+B) % mod << "\n";
    }    

    return 0;
}