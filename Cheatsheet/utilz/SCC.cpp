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