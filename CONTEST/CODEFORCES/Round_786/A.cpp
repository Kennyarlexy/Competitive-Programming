#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int x, y; cin >> x >> y;
        if (y % x == 0) {
            cout << "1 " << y / x << "\n";
        } else {
            cout << "0 0\n";
        }
    }

    return 0;
}