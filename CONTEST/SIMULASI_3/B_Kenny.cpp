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
    ll n, k, l; cin >> n >> k >> l;
    ll total = 0;
    for (ll i = 1; i <= n; i++) {
        ll T; cin >> T;
        total += T;
    }

    ll need = total - l;
    ll buy =  max(0LL, (need + (k - 1)) / k);
    cout << buy << "\n";

    return 0;
}