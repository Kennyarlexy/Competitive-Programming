#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int INF = 1e9;

vector<vector<pair<int, int>>> adj;
vector<int> dist;

void djikstra(int start, int finish) {
    priority_queue<pair<int, int>> PQ;
    PQ.push({0, start});
    dist[start] = 0;

    while (!PQ.empty()) {
        auto [d, u] = PQ.top(); PQ.pop();
        d *= -1;
        
        if (u == finish) break;
        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                PQ.push({-1*(dist[u] + w), v});
                dist[v] = dist[u] + w;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, M; cin >> N >> M;
        int start, finish; cin >> start >> finish;

        adj = vector<vector<pair<int, int>>> (N);
        dist = vector<int> (N, INF);
        for (int i = 1; i <= M; i++) {
            int u, v, w; cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        djikstra(start, finish);

        cout << "Case #" << t << ": ";
        if (dist[finish] == INF) {
            cout << "unreachable\n";
        } else {
            cout << dist[finish] << "\n";
        }
    }
    
    return 0;
}