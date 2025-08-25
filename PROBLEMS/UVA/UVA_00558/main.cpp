#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, M; cin >> N >> M;

        vector<tuple<int, int, int>> adj; adj.reserve(M);
        vector<int> dist(N, INF);
        for (int i = 1; i <= M; i++) {
            int u, v, w; cin >> u >> v >> w;
            adj.push_back({u, v, w});
        }
        
        dist[0] = 0;
        
        int i;
        for (i = 1; i <= N; i++) {
            bool modified = false;
            for (int j = 0; j < M; j++) {
                auto [u, v, w] = adj[j];
                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    modified = true;
                }
            }

            if (!modified) break;
        }

        if (i > N) cout << "possible\n";
        else cout << "not possible\n";
    }
    
    return 0;
}