#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

string grid[105];
bool vis[105][105];
ll R, C;

bool canEscape = false;
bool caught = false;

void bfs(ll sr, ll sc) {
    queue<ll> Qr; Qr.push(sr);
    queue<ll> Qc; Qc.push(sc);
    vis[sr][sc] = true;

    ll dr[] = {1, 0, -1, 0};
    ll dc[] = {0, 1, 0, -1};
    while (!Qr.empty()) {
        ll cr = Qr.front(); Qr.pop();
        ll cc = Qc.front(); Qc.pop();
        if (cr == 0 || cr == R-1 || cc == 0 || cc == C-1) canEscape = true;
        if (grid[cr][cc] == 'D') caught = true;
        for (ll i = 0; i < 4; i++) {
            ll nr = cr + dr[i];
            ll nc = cc + dc[i];
            if (vis[nr][nc]) continue;
            if (nr < 0 || nr >= R) continue;
            if (nc < 0 || nc >= C) continue;
            if (grid[nr][nc] == '-' || grid[nr][nc] == '|' || grid[nr][nc] == 'x') continue;

            Qr.push(nr);
            Qc.push(nc);
            vis[nr][nc] = true;
        }
    }
}


int main() {
    fast_io();
    //use ll when possible!
    cin >> R >> C;
    cin.ignore(1000, '\n');
    for (ll r = 0; r < R; r++) {
        getline(cin, grid[r]);
    }

    for (ll r = 0; r < R; r++) {
        for (ll c = 0; c < C; c++) {
            if (grid[r][c] == 'C') {
                bfs(r, c);
                break;
            }
        }
    }

    if (caught) cout << "Dawala bertemu Cepot\n";
    else cout << "Dawala tidak bertemu Cepot\n";

    if (canEscape) cout << "ada jalan Cepot lumpat\n";
    else cout << "tidak ada jalan Cepot lumpat\n";

    return 0;
}

/*
10
8
|------|
|xxxx  |
|  C   |
|      |
       |
|      |
|------|
|xx   x|
|   D  |
|------|

10
8
|------|
|xxxx  |
|  C   |
|      |
|      |
|      |
|-- ---|
|xx   x|
|   D  |
|------|


10
8
|------|
|xxxx  |
|  D   |
|      |
|      |
|      |
|-- ---|
|xx   x|
|   C  |
|--- --|

10
8
|------|
|xxxx  |
|  D   |
|      |
|      |
|      |
|------|
|xx   x|
|   C  |
|------|

10
8
|------|
|xxxx  |
| xDx  |
| x x  |
|      |
|      |
|xxxxxx|
|xx   x|
|   C   
|------|
*/