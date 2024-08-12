#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll N, M;
ll S[2505];
vector<ll> iK[2505]; //index of ch
// bool vis[2505][2505];
ll res = LONG_LONG_MAX;

void dfs(ll start, ll i, ll total) {
    if (i == N) {
        res = min(res, total);
        // cout << "Entered\n" << "Total = " << total << "\n";;
        return;
    }

    // vis[start][i] = true;
    for (auto& next : iK[S[i+1]]) {
        // if (vis[next][i+1]) continue;
        if (next == start) dfs(next, i+1, total);
        else dfs(next, i+1, total + abs(start - next));
    }
}

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        memset(iK, 0, sizeof(iK));
        // memset(vis, 0, sizeof(vis));
        res = LONG_LONG_MAX;
        cin >> N;
        for (ll i = 1; i <= N; i++) {
            cin >> S[i];
        }

        cin >> M;
        for (ll i = 1; i <= M; i++) {
            ll ch; cin >> ch;
            iK[ch].push_back(i);
        }

        for (auto& start : iK[S[1]]) {
            dfs(start, 1, 0);
            // cout << "start at " << start << "\n";
        }

        cout << "Case #" << t << ": " << res << "\n";
    }

    return 0;
}