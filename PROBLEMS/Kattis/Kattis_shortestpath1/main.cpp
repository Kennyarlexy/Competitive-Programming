#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second 
using namespace std;

const ll INF = 1e18;
vector<vector<pair<ll, ll>>> adj;
vector<ll> dist;
vector<bool> processed;

void djikstra(int s) {
    priority_queue<pair<ll, ll>> PQ;
    PQ.emplace(0, s); // {dist, node}, min PQ
    dist[s] = 0;

    while (!PQ.empty()) {
        int u = PQ.top().se; PQ.pop();
        if (processed[u]) continue;
        // min distance for this node is final ONCE it's retrieved from the PQ for the first time
        processed[u] = true;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                PQ.emplace(-dist[v], v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, Q, s;
    int TC = 0;
    while (cin >> n >> m >> Q >> s && (n || m || Q || s)) {
        TC++;
        if (TC > 1) cout << "\n";
        adj = vector<vector<pair<ll, ll>>> (n+5);
        dist = vector<ll> (n+5, INF);
        processed = vector<bool> (n+5);

        for (int i = 1; i <= m; i++) {
            ll u, v, w; cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
        }

        djikstra(s);
        for (int q = 1; q <= Q; q++) {
            int v; cin >> v;
            if (dist[v] == INF) cout << "Impossible\n";
            else cout << dist[v] << "\n";
        }        
    }
    
    return 0;
}

/*
4 3 4 0
0 1 2
1 2 2
3 0 2
0
1
2
3
*/