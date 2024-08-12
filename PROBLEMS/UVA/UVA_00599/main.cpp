#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> adj[300];
bool vis[300];
ll dfs(ll u, ll k) {
    if (vis[u]) return k;

    vis[u] = true;
    for (auto& v : adj[u]) {
        k = dfs(v, k);
    }
    return k+1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        memset(adj, 0, sizeof(adj));
        memset(vis, 0, sizeof(vis));
        while (true) {
            string line; cin >> line;
            if (line[0] == '*') break;
            adj[line[1]].push_back(line[3]);
            adj[line[3]].push_back(line[1]);
        }

        string line; cin >> line;
        vector<ll> all;
        for (ll i = 0; i < line.length(); i+=2) {
            all.push_back(line[i]);
        }

        ll tree = 0, acorn = 0;
        for (auto& u : all) {
            if (vis[u]) continue;
            if (dfs(u, 0) > 1) tree++;
            else acorn++;
        }

        cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s).\n";
    }
    
    return 0;
}