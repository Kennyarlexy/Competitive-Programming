#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second 
using namespace std;

const int INF = 1e9;

map<int, vector<int>> adj;
map<int, bool> vis;
map<int, int> dist;

void bfs(int s) {
    queue<int> Q;
    Q.push(s);
    vis[s] = true;
    dist[s] = 0;
    
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (auto v : adj[u]) {
            if (vis[v]) continue;

            vis[v] = true;
            dist[v] = dist[u] + 1;
            Q.push(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 0;
    while (true) {
        int N; cin >> N;
        if (N == 0) break;

        adj = {};
        for (int i = 1; i <= N; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        while (true) {
            int u, TTL; cin >> u >> TTL;
            if (u == 0 && TTL == 0) break;

            vis = {}; dist = {};
            bfs(u);
            int cnt = 0;
            for (auto [x, d] : dist) {
                if (d <= TTL) cnt++;
            }
            int n = adj.size();

            cout << "Case " << ++T << ": " << n - cnt << " nodes not reachable from node " << u << " with TTL = " << TTL << ".\n";
        }
    }
    
    return 0;
}