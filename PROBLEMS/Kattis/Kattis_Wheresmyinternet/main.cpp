#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> adj[200005];
bool vis[200005];
void dfs(int u) {
    if (vis[u]) return;

    vis[u] = true;
    for (auto v : adj[u]) {
        dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    vector<int> V;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) V.push_back(i);
    }

    if (V.size() == 0) {
        cout << "Connected\n";
    } else {
        for (auto u : V) {
            cout << u << "\n";
        }
    }
    
    return 0;
}