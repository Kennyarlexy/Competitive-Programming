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
    ll n; cin >> n;
    ll Min = LONG_LONG_MAX;
    ll iMin = 0;
    for (ll i = 0; i < n; i++) {
        ll a; cin >> a;
        if (a < Min) {
            Min = a;
            iMin = i;
        }
    }

    cout << iMin << "\n";

    return 0;
}