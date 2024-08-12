#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll x, y, n; 
ll f(ll t) {
    ll nx = t/x;
    ll ny = t/y;

    return nx + ny;
}

int main() {
    fast_io();
    //use ll when possible!
    cin >> x >> y >> n;
    ll t = 1e18;
    for (ll step = t/2; step >= 1; step /= 2) {
        while (t-step >= 0 && f(t-step) >= n) t -= step;
    }

    cout << t << "\n";

    return 0;
}