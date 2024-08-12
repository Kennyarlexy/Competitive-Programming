#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

ll A[300005];
vector<vector<int>> adj;

pair<ll, ll> dfs(int u, int p) {
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        adj = {};
        adj.resize(n+1);
        
        for (int i = 1; i <= n; i++) cin >> A[i];

        for (int i = 1; i < n; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }


    }
    
    return 0;
}