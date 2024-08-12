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
    ll total = 0;
    for (ll t = 1; t <= T; t++) {
        double l, w, d, weight;
        cin >> l >> w >> d >> weight;
        bool allowed = ((l <= 56 && w <= 45 && d <= 25) || l+w+d <= 125) && weight <= 7;
        total += allowed;
        cout << allowed << "\n";
    }
    cout << total << "\n";

    return 0;
}