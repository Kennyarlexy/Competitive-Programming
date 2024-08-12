#include <bits/stdc++.h>
#define ll long long
using namespace std;

char A[15][15];
char res[15][15];
ll dr[] = {-1, 0, 1, 0};
ll dc[] = {0, 1, 0, -1};
bool vis[15][15];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, M;
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        
        memset(vis, 0, sizeof(vis));
        ll sr, sc; cin >> sr >> sc;
        for (ll r = 1; r <= N; r++) {
            for (ll c = 1; c <= M; c++) {
                cin >> A[r][c];
                res[r][c] = '?';
            }
        }

        res[sr][sc] = '0';
        vis[sr][sc] = true;
        ll cr = sr, cc = sc;
        ll moves = 0;
        while (true) {
            bool OK = false;
            ll nr, nc;
            for (ll i = 3; i >= 0; i--) {
                ll _nr = cr + dr[i];
                ll _nc = cc + dc[i];
                res[_nr][_nc] = A[_nr][_nc];
                if (vis[_nr][_nc]) continue;
                if (_nr < 1 || _nr > N) continue;
                if (_nc < 1 || _nc > M) continue;
                if (A[_nr][_nc] == 'X') continue;

                OK = true;
                nr = _nr, nc = _nc;
            }
            if (!OK) break;
            moves++;
            cr = nr, cc = nc;
            vis[nr][nc] = true;
        }

        cout << "\n";
        for (ll r = 1; r <= N; r++) {
            for (ll c = 1; c <= M; c++) {
                cout << "|---";
            }
            cout << "|\n";

            for (ll c = 1; c <= M; c++) {
                cout << "| " << res[r][c] << " ";
            }
            cout << "|\n";
        }

        for (ll c = 1; c <= M; c++) {
            cout << "|---";
        }
        cout << "|\n\n";

        cout << "NUMBER OF MOVEMENTS: " << moves << "\n";
    }
    
    return 0;
}

/*
5 5
1 3
X X 0 0 X
X X 0 0 X
X 0 X 0 X
X 0 0 0 X
X X X X X
5 5
1 1
0 0 X X X
X X 0 0 X
X 0 0 0 X
X 0 0 0 X
X X X X X
0 0
*/