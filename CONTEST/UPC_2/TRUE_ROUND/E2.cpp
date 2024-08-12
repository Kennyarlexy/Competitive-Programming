#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    ll x, y; cin >> x >> y;
    if (x > y) swap(x, y);

    int target = round((double) y / x);

    // if (y) target++;
    // cout << "target = " << target << "\n";
    ll move = 0;
    while ((double ) y / x != target) {
        // if (abs(y / (x + 1.0) - target) < abs((y+1.0) / x - target)) {
        //     x++;
        // } else {
        //     y++;
        // }

        if ((double) y / x > target) {
            x++;
        } else {
            y++;
        }
        move++;
    }

    cout << move << "\n";


    return 0;
}