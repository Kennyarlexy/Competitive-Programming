#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll h, w, xa, ya, xb, yb;
        cin >> h >> w >> xa >> ya >> xb >> yb;

        if (xb < xa) {
            cout << "Draw\n";
            continue;
        }

        ll m = (xb+xa+1)/2;
        ll ka = max(0LL, m-xa);
        ll kb = max(0LL, xb-m);
        // cout << ka << " " << kb << "\n";

        ll la = max(1LL, ya - ka);
        ll ra = min(w, ya + ka);

        ll lb = max(1LL, yb - kb);
        ll rb = min(w, yb + kb);

        if ((xb-xa+1) % 2 == 0) {
            if (la <= lb && ra >= rb) cout << "Alice\n";
            else cout << "Draw\n";
        } else {
            if (lb <= la && rb >= ra) cout << "Bob\n";
            else cout << "Draw\n";
        }
    }
    
    return 0;
}