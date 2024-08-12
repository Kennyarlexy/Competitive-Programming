#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

vector<pair<ll, ll>> FP; 

int main() {
    fast_io();
    //use ll when possible!
    ll N, M, K, Q; cin >> N >> M >> K >> Q;
    for (ll r = 1; r <= N; r++) {
        for (ll c = 1; c <= M; c++) {
            char ch; cin >> ch;
            if (ch == 'X') FP.emplace_back(r, c);
        }
    }

    for (ll q = 1; q <= Q; q++) {
        ll r, c; cin >> r >> c;
        ll res = LONG_LONG_MAX;
        for (auto& pos : FP) {
            res = min(res, abs(pos.first-r) + abs(pos.second-c));
        }
        cout << res << "\n";
    }

    return 0;
}