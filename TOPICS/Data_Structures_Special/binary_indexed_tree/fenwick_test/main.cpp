#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll LSOne(ll n) {
    return n & -n;
}

int main() {
    // fast_io();
    //use ll when possible!
    ll n;
    while (cin >> n) {
        cout << n + LSOne(n) << "\n";
    }

    return 0;
}