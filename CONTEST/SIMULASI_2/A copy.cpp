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
        set<ll> unique;
        for (ll i = 0; i < n; i++) {
            ll a; cin >> a;
            unique.insert(a);
        }
        ll res = unique.size() - 2;
        cout << max(0LL, res) << "\n";
        //WA
    }

    //ada test case?
    //pindah file
    return 0;
}