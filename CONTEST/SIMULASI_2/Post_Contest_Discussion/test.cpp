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
    ll a = 100;
    ll b = 54;
    ll mod = 10;

    ll res = (a-b) % mod;
    ll A = (a%mod - b%mod + mod) % mod;
    ll B = a%mod - b%mod;
    if (B < 0) B += mod;

    cout << res << "\n";
    cout << A << " " << B <<"\n";

    return 0;
}