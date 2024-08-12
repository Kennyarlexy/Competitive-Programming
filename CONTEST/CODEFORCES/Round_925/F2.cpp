#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<set<int>> adj;
vector<bool> vis1, vis2;

bool dfs(int u) {
    if (vis1[u]) return vis2[u];

    vis1[u] = vis2[u] = true;
    for (auto v : adj[u]) {
        if (dfs(v)) return true;
    }
    vis2[u] = false;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, k; cin >> n >> k;
        adj = vector<set<int>> (n+5);
        vis1 = vis2 = vector<bool> (n+5);
        for (int i = 1; i <= k; i++) {
            int v = -1;
            for (int j = 1; j <= n; j++) {
                int u; cin >> u;
                if (j == 1) continue;
                if (v != -1) adj[v].insert(u);
                v = u;
            }
        }

        bool ans = true;
        for (int i = 1; i <= n; i++) {
            if (dfs(i)) {
                ans = false;
                break;
            }
        }
        
        cout << (ans ? "YES":"NO") << "\n";
    }
    
    return 0;
}