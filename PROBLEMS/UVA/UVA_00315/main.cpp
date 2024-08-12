#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int UNVISITED = -12345678;

vector<vector<int>> adj;
vector<int> dfs_num, dfs_low;
vector<bool> critical;
int root, children_cnt = 0;
int itr = 0;

void dfs(int u, int p) {
    dfs_num[u] = dfs_low[u] = itr++;
    
    for (auto v : adj[u]) {
        if (v == p) continue;
        if (dfs_num[v] != UNVISITED) { // visited
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
            continue;
        }

        if (u == root) children_cnt++;
        dfs(v, u);
        dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        if (dfs_low[v] >= dfs_num[u]) critical[u] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n && n) {
        adj = vector<vector<int>> (n+1);
        dfs_num = dfs_low = vector<int> (n+1, UNVISITED);
        critical = vector<bool> (n+1);
        itr = 0;

        string line;
        cin.ignore(1000, '\n');
        while (true) {
            getline(cin, line);
            stringstream SS(line);
            int u; SS >> u;
            if (u == 0) break;

            int v;
            while (SS >> v) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

// inside main
for (int i = 1; i <= n; i++) {
    if (dfs_num[i] != UNVISITED) continue;            
    root = i, children_cnt = 0;
    dfs(i, 0);
    critical[root] = (children_cnt > 1);
}

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (critical[i]) cnt++;
        }

        cout << cnt << "\n";
    }
    
    return 0;
}

/*
5
5 1 2 3 4
0
6
2 1 3
5 4 6 2
0
5
5 1 2 3 4
0
6
2 1 3
5 4 6 2
0
0

13
1 3 6 13
2 6 9 10 13
3 4 5 13
4 5 7 12
5 6 11 13
6 9
8 11
9 10
11 13
12 13
0
0
*/