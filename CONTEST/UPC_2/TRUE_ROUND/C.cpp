#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int x; cin >> x;
        if (x <= 0) {
            cout << "1\n";
            continue;
        }
        // double pow_2 = log(x) / log(2);
        // double pow_3 = log(x) / log(3);
        // int pow2 = ceil(pow_2);
        // int pow3 = ceil(pow_3);
        // ll res = min(powl(2, pow2), powl(3, pow3));
        // cout << res << "\n";

        ll pow_2 = 1, pow_3 = 1;
        while (x > pow_2) {
            pow_2 *= 2;
        }

        while (x > pow_3) {
            pow_3 *= 3;
        }

        ll res = min(pow_2, pow_3);
        cout << res << "\n";
    }

    return 0;
}