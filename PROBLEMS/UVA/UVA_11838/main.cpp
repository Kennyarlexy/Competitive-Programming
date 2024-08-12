#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> adj;
vector<int> dfs_num, dfs_low;
vector<bool> active;
stack<int> st;
const int UNVISITED = -12345678;
int n, m;
int itr = 0;
int SCC = 0; // SCC count

void dfs(int u) {
    st.push(u);
    dfs_num[u] = dfs_low[u] = itr++;
    active[u] = true;
    for (auto v : adj[u]) {
        if (dfs_num[v] == UNVISITED) {
            dfs(v);
        }

        if (active[v]) {
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
    }

    if (dfs_num[u] == dfs_low[u]) {
        SCC++;
        while (true) {
            int v = st.top(); st.pop();
            active[v] = false;
            if (v == u) break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> m && (n || m)) {        
        adj = vector<vector<int>> (n+1);
        dfs_num = dfs_low = vector<int> (n+1, UNVISITED);
        active = vector<bool> (n+1);
        st = {};
        SCC = 0;
        itr = 0;

        for (int i = 1; i <= m; i++) {
            int u, v, type;
            cin >> u >> v >> type;
            adj[u].push_back(v);
            if (type == 2) adj[v].push_back(u);
        }

// inside main
for (int i = 1; i <= n; i++) {
    if (dfs_num[i] != UNVISITED) continue;
    dfs(i);
}

        if (SCC == 1) cout << "1\n";
        else cout << "0\n";
    }
    
    return 0;
}

/*
4 5
1 2 1
1 3 2
2 4 1
3 4 1
4 1 2
3 2
1 2 2
1 3 2
3 2
1 2 2
1 3 1
4 2
1 2 2
3 4 2
4 5
1 2 1
1 3 2
2 4 1
3 4 1
4 1 2
3 2
1 2 2
1 3 2
3 2
1 2 2
1 3 1
4 2
1 2 2
3 4 2
0 0

*/