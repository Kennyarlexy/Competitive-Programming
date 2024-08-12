#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll M[1005];
vector<ll> adj[1005];
bool vis[1005];

ll dfs(ll u) {
    if (vis[u]) return 0;

    vis[u] = true;
    ll jumlah = M[u];
    for (auto& v : adj[u]) {
        jumlah += dfs(v);
    }

    return jumlah;
}

int main() {
    fast_io();
    //use ll when possible!
    ll N, K; cin >> N >> K;
    for (ll i = 1; i <= N; i++) {
        cin >> M[i];
    }
    for (ll e = 1; e <= K; e++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> monster;
    for (ll u = 1; u <= N; u++) {
        monster.push_back(dfs(u));
    }

    sort(monster.begin(), monster.end(), greater<ll> ());
    ll k = 0;
    ll res = 0;
    for (ll i = 0; i < monster.size(); i++) {
        k++;
        res += k*monster[i];
    }

    cout << res << "\n";

    return 0;
}