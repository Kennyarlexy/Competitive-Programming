#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

vector<bool> vis[3];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
char A[3][200005];

bool dfs(int r, int c, int n) {
    if (vis[r][c]) return false;
    if (r == 2 && c == n) return true;

    vis[r][c] = true;
    if ((r+c) % 2 == 0) {
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 1 || nr > 2) continue;
            // if (nc < 1 || nc > n) continue;
            if (dfs(nr, nc, n)) return true;
        }
    } else {
        int nr = r;
        int nc = (A[r][c] == '<') ? c-1 : c+1;
        if (dfs(nr, nc, n)) return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll n; cin >> n;
        for (int i = 1; i <= 2; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> A[i][j];
            }
        }

        vis[1] = vis[2] = vector<bool> (n+5);
        bool ans = dfs(1, 1, n);
        cout << (ans ? "YES":"NO") << "\n";
    }
    
    return 0;
}