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
        ll a, b, r; cin >> a >> b >> r;

        ll y = a ^ b;
        ll LSOne = ((y) & (-y));
        while (y > 0 && r >= LSOne) {
            y -= LSOne;
            r -= LSOne;
            LSOne = ((y) & (-y));
        }

        cout << y << "\n";
    }
    
    return 0;
}