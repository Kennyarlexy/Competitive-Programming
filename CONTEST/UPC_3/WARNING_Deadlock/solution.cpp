#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> adj[100005];
bool visited[100005];
bool visiting[100005];

bool dfs(ll u, ll prev) {
    if (visited[u]) return visiting[u];

    visited[u] = true;
    visiting[u] = true;

    bool foundCycle = false;
    for (auto v : adj[u]) {
        if (v != prev && dfs(v, u)) {
            foundCycle = true;
            break;
        }
    }

    visiting[u] = false;
    return foundCycle;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, M; cin >> N >> M;
    for (ll e = 1; e <= M; e++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    bool foundCycle = false;
    for (ll u = 1; u <= N; u++) {
        if (dfs(u, -1)) {
            foundCycle = true;
            break;
        }
    }

    if (foundCycle) cout << "[WARNING] Deadlock Detected!\n";
    else cout << "[INFO] Everything OK\n";
    
    return 0;
}

/*

Topic: DFS (cycle check)
Problem Statement Idea: Deadlock, is the system currently experiencing deadlock?
Input Format:
N M
u1 v1
u2 v2
...
uM vM

Output Format:
YES/NO

*/