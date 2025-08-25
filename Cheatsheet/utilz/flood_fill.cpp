#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

bool vis[1005][1005];

void flood_fill(ll sr, ll sc) {
    queue<ll> Qr; Qr.push(sr);
    queue<ll> Qc; Qc.push(sc);
    vis[sr][sc] = true;

    ll dr[] = {1, 0, -1, 0};
    ll dc[] = {0, 1, 0, -1};
    
    // flood-fill 8
    // ll dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
    // ll dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

    while (!Qr.empty()) {
        ll cr = Qr.front(); Qr.pop();
        ll cc = Qc.front(); Qc.pop();
        for (ll i = 0; i < 4; i++) {
            ll nr = cr + dr[i];
            ll nc = cc + dc[i];
            // constraint > 0
            if (vis[nr][nc]) continue;

            Qr.push(nr);
            Qc.push(nc);
            vis[nr][nc] = true;
        }
    }
}
