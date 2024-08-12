#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll cnt[300];
pair<char, ll> I[] = {
    {'M', 1},
    {'A', 3},
    {'R', 2},
    {'G', 1},
    {'I', 1},
    {'T', 1}
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        memset(cnt, 0, sizeof(cnt));
        string s; cin >> s;
        for (auto& ch : s) {
            cnt[ch]++;
        }

        ll res = LONG_LONG_MAX;
        for (ll i = 0; i < 6; i++) {
            res = min(res, cnt[I[i].fi] / I[i].se);
        }
        cout << res << "\n";
    }
    
    return 0;
}