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
    ll v, t;
    while (cin >> v >> t) {
        ll dist = v*t*2;
        cout << dist << "\n";
    }

    return 0;
}