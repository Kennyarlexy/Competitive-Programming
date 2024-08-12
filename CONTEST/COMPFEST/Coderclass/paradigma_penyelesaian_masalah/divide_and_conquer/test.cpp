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
    map<ll, ll> test;
    test[0]++;
    test[0]++;
    test[0]++;
    cout << test[0] << "\n";
    for (ll i = 1; i <= 100; i++) {
        test[i] += 2;
    }

    for (auto& [u, v] : test) {
        cout << u << " " << v << "\n";
    }

    return 0;
}