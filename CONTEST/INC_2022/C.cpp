#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll cnt[500005];

int main() {
    fast_io();
    //use ll when possible!
    ll cnt_cell = 0;
    ll Q; cin >> Q;
    for (ll q = 1; q <= Q; q++) {
        char sign;
        ll x;
        cin >> sign >> x;
        if (sign == '+') {
            cnt[x]++;
            while (cnt[x] == 2) {
                cnt[x+1]++;
                cnt[x] = 0;
                x++;
                cnt_cell--;
            }

            if (cnt[x] == 1) {
                cnt_cell++;
            } else if (cnt[x] == 0) {
                cnt_cell--;
            }
        } else {
            cnt[x]--;
            while (cnt[x] == -2) {
                cnt[x+1]--;
                cnt[x] = 0;
                x++;
                cnt_cell--;
            }

            if (cnt[x] == 0) {
                cnt_cell--;
            } else if (cnt[x] == -1) {
                cnt_cell++;
            }
        }
        if (cnt_cell == 0) cout << "YES\n";
        else cout << "NO\n";
        // cout << cnt_cell << "\n";
    }

    return 0;
}