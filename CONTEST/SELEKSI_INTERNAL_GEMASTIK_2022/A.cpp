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

    ll w, h;
    while (cin >> w >> h) {
        ll gcd = __gcd(w, h);
        w /= gcd;
        h /= gcd;

        cout << w << ":" << h << "\n";
    }

    return 0;
}