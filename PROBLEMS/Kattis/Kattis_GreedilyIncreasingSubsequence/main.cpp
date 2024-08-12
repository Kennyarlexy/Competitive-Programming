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
    ll N; cin >> N;
    ll prev; cin >> prev;
    vector<ll> res;
    res.push_back(prev);
    for (ll i = 2; i <= N; i++) {
        ll a; cin >> a;
        if (a > prev) {
            res.push_back(a);
            prev = a;
        }
    }
    
    cout << res.size() << "\n";
    for (auto& a : res) {
        cout << a << " ";
    }
    cout << "\n";

    return 0;
}