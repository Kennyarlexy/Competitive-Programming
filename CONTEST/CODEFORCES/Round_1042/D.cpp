#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> cnt;

int dfs(int u, int x) {
    vis[u] = true;
    int is_leaf = 1;
    int _cnt = 0;
    for (auto v : adj[u]) {
        if (!vis[v]) {
            is_leaf = 0;
            _cnt += dfs(v, x);
        }
    }

    
    if (u == x) {
        is_leaf = 0;
// cout << "XXXX\n";
    }
// if (is_leaf) cout << u << " is leaf\n";
    return _cnt + is_leaf;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        adj = vector<vector<int>>(n+1);
        vis = vector<bool> (n+1);
        cnt = vector<int> (n+1);
        for (int i = 1; i < n; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            cnt[u]++;
            cnt[v]++;
        }

        int mx = 1;
        for (int u = 1; u <= n; u++) {
            if (cnt[u] > cnt[mx]) {
                mx = u;
            }
        }

        if (cnt[mx] == 2 && n > 3) {
            cout << "1\n";
            continue;
        }

        // cout << "mx = " << mx << "\n";

        int ans = 0;
        vis[mx] = true;
        for (auto u : adj[mx]) {
// cout << "start from " << u << "\n";
            ans += dfs(u, u);
        }

        cout << ans << "\n";
    }
    
    return 0;
}