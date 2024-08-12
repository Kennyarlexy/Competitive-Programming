#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll N, M, K, Q;
char grid[1005][1005];
bool vis[1005][1005];
ll dr[] = {1, 0, -1, 0};
ll dc[] = {0, 1, 0, -1};

ll bfs(ll sr, ll sc) {
    queue<ll> qr, qc;
    qr.push(sr);
    qc.push(sc);
    vis[sr][sc] = true;

    vector<ll> visr, visc;
    visr.push_back(sr);
    visc.push_back(sc);

    ll dist = 0;
    while (!qr.empty()) {
        ll cr = qr.front(); qr.pop();
        ll cc = qc.front(); qc.pop();
        if (grid[cr][cc] == 'X') {
            dist = abs(sr-cr) + abs(sc-cc);
            break;
        }
        for (ll i = 0; i < 4; i++) {
            ll nr = cr + dr[i];
            ll nc = cc + dc[i];
            if (nr < 1 || nr > N) continue;
            if (nc < 1 || nc > M) continue;
            if (vis[nr][nc]) continue;

            vis[nr][nc] = true;
            visr.push_back(nr); visc.push_back(nc);
            qr.push(nr); qc.push(nc);
        }
    }

    for (ll i = 0; i < visr.size(); i++) {
        vis[visr[i]][visc[i]] = false;
    }

    return dist;
}

int main() {
    fast_io();
    //use ll when possible!
    cin >> N >> M >> K >> Q;
    for (ll r = 1; r <= N; r++) {
        for (ll c = 1; c <= M; c++) {
            cin >> grid[r][c];
        }
    }

    for (ll i = 1; i <= Q; i++) {
        ll r, c; cin >> r >> c;
        ll res = bfs(r, c);
        cout << res << "\n";
    }

    return 0;
}