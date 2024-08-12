#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> adj[100005];
ll State[100005];
bool vis[100005];
bool propagated[100005];
ll cnt[2];

void dfs(ll u, bool state) {
    if (vis[u]) return;

    vis[u] = true;
    State[u] = state;
    cnt[State[u]]++;
    for (auto& v : adj[u]) {
        dfs(v, !state);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //use ll when possible!
    
    ll N; cin >> N;
    for (ll i = 1; i < N; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 1);

    ll max_bipartite_state = (cnt[1] > cnt[0] ? 1 : 0);

    bool flag = false;
    ll edge = N-1;
    ll node = max(cnt[0], cnt[1]);

    // if (cnt[0] + cnt[1] == N) cout << "OK\n";
    for (ll u = 1; u <= N; u++) {
        if (State[u] == max_bipartite_state) continue;
        if (adj[u].size() > 1) continue;

        // kalau ketemu leaf
        node++;
        if (!propagated[adj[u][0]]) { // kalau yang tetangga yang belum propagate
            node--; // ganti statenya, sudah tidak masuk 
            propagated[adj[u][0]] = true; // supaya tidak 
        }
    }

    cout << node * edge << "\n";
    // cout << cnt[1] << " " << cnt[0] << " " << edge << "\n";
    
    return 0;
}




/*
8
1 2
1 3
1 4
1 5
5 6
5 7
2 8


15
1 2
2 3
3 4
3 5
3 6
3 7
3 8
3 9
1 10
1 11
1 12
1 13
1 14
1 15

*/