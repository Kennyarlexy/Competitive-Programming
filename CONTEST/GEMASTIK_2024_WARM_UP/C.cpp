#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;


vector<int> adj[100005];
ll pts[100005];
ll 
void dfs(int u, int p) {
    pts[u] += u;
    ++hi;
    for (auto v : adj[u]) {
        dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for (ll i = 2; i <= 100000; i++) {
        int u = (rand() % (i-1) + 1);
        cout << u << "\n";
        adj[u].push_back(i);
        adj[i].push_back(u);
        
    }

    dfs(1);

    
    return 0;
}
/*
13
1 2 3 1 1 2 6 6 2 5 7 10 7
*/