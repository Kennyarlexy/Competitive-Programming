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
    if (y % x == 0) {
        cout << "0\n";
        return 0;
    } else if (y / x == 1) {
        cout << y % x << "\n";
        return 0;
    }


    ll x1 = x, y1 = y;
    ll x2 = x, y2 = y;

    ll move = 0;
    while (y1 % x1 != 0 && y2 % x2 != 0) {
        ll temp_x1, temp_x2, temp_y1, temp_y2;

        if (((x1 + 1) - (y1 % (x1 + 1))) % (x1 + 1) < (x2 + 1) - (y2 % (x2 + 1)) % (x2 + 1)) {
            temp_x1 = x1 + 1;
            temp_y1 = y1;
        } else {
            temp_x1 = x2 + 1;
            temp_y1 = y2;
        }

        if ((x1 - ((y1+1) % x1)) % x1 < (x2 - ((y2+1) % x2)) % x2) {
            temp_x2 = x1;
            temp_y2 = y1 + 1;
        } else {
            temp_x2 = x2;
            temp_y2 = y2 + 1;
        }
        x1 = temp_x1;
        y1 = temp_y1;
        x2 = temp_x2;
        y2 = temp_y2;
        move++;
    }

    cout << move << "\n";

    return 0;
}