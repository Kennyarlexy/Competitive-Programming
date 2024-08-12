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
    ll n = 500;
    ll mod = 1e9;

    ll res = 1;
    while (n > 1) {
        res *= n;
        n--;
        while (res % 10 == 0) res /= 10;
        res = res % mod;
    }
    cout << res % 10 << "\n";

    return 0;
}