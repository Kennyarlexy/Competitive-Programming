#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll x, y, k; cin >> x >> y >> k;
        while (x > 1 && k > 0) {
            // ll z = (x + y - 1) / y * y;
            ll z = (x/y + 1) * y;
            ll d = min(k, z-x);

            x += d;
            k -= d;

            while (x % y == 0) {
                x /= y;
            }
        }

        

        k = k % (y - 1);
        x += k;

        // while (x % y == 0 && k > 0) x /= y;

        cout << x << "\n";
    }
    
    return 0;
}

/*
1
24 5 5
*/