#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

int cnt[200005];
vector<vector<int>> adj;

int dfs1(int u) {
    cnt[u] = 1;
    for (auto v : adj[u]) {
        cnt[u] += dfs1(v);
    }

    return cnt[u];
}

int dfs2(int u, int k) {
    int total = 0;
    int _max_v = -1; // the index
    for (auto v : adj[u]) {
        total += cnt[v];
        if (_max_v == -1 || cnt[v] > cnt[_max_v]) _max_v = v;
    }

    if (_max_v == -1) return 0; // leaf

    int _max = cnt[_max_v];
  
    if (_max - k <= total - _max) {
        return (total-k)/2;
    }

    if (adj[u].size() > 1) {
        return total - _max + dfs2(_max_v, k + (total - _max) - 1);
    } else {
        return dfs2(adj[u][0], max(0, k-1));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        adj = vector<vector<int>> (n+5);
        for (int i = 2; i <= n; i++) {
            int u; cin >> u;
            adj[u].push_back(i);
        }

        dfs1(1);
        int ans = dfs2(1, 0);

        cout << ans << "\n";
    }
    
    return 0;
}

/*
1
52
49 21 22 25 7 38 14 17 46 5 35 36 1 28 11 26 9 32 36 20 28 39 5 26 45 8 23 23 41 42 6 18 38 32 40 1 10 16 14 17 46 6 31 43 37 35 13 50 51 33 1
*/