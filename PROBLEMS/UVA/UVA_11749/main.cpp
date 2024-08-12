#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

ll k = 0;
void dfs(int u) {
    vis[u] = true;

    k++;
    for (auto v : adj[u]) {
        if (vis[v]) continue;
        dfs(v);
    }
}

tuple<ll, ll, ll> EL[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m && (n || m)) {
        adj = vector<vector<int>> (n+1);
        vis = vector<bool> (n+1);
        
        ll mx_w = LLONG_MIN;
        for (int i = 1; i <= m; i++) {
            ll u, v, w;
            cin >> u >> v >> w;
            EL[i] = {u, v, w};
            mx_w = max(mx_w, w);
        }

        for (int i = 1; i <= m; i++) {
            auto [u, v, w] = EL[i];
            if (w < mx_w) continue;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        ll mx_k = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;

            k = 0;
            dfs(i);
            mx_k = max(mx_k, k);
        }

        cout << mx_k << "\n";
    }
    
    return 0;
}

/*
4 5
1 2 100
1 3 100
1 4 1
2 3 100
3 4 1
9 14
1 2 9
6 9 8
2 4 9
2 3 9
4 5 1
4 3 9
5 9 2
9 8 9
7 8 9
7 9 5
6 7 9
5 6 4
5 8 7
7 5 9
4 5
1 2 100
1 3 100
1 4 1
2 3 100
3 4 1
9 14
1 2 9
6 9 8
2 4 9
2 3 9
4 5 1
4 3 9
5 9 2
9 8 9
7 8 9
7 9 5
6 7 9
5 6 4
5 8 7
7 5 9
0 0

*/