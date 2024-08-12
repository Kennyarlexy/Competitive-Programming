#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll grid[105][105];

int main() {
    fast_io();
    //use ll when possible!
    ll R, C; cin >> R >> C;
    for (ll r = 1; r <= R; r++) {
        for (ll c = 1; c <= C; c++) {
            cin >> grid[r][c];
        }
    }

    for (ll r = 1; r <= R; r++) {
        for (ll c = 2; c <= C; c++) {
            grid[r][c] += grid[r][c-1];
        }
    }

    ll res = LONG_LONG_MIN;
    for (ll left = 1; left <= C; left++) {
        for (ll right = left; right <= C; right++) {
            ll max_for_cur_width = LONG_LONG_MIN;
            ll cur = 0;
            for (ll r = 1; r <= R; r++) {
                ll sum = grid[r][right];
                if (left > 1) sum -= grid[r][left-1];

                cur = max(cur + sum, sum);
                max_for_cur_width = max(max_for_cur_width, cur);
            }
            res = max(res, max_for_cur_width);
        }
    }

    cout << res << "\n";

    return 0;
}