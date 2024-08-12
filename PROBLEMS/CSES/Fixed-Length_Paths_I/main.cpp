#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> adj[200005];
int sz[200005]; // subtree sz
int cnt[200005]; // cnt[x] = how many nodes with distance x
bool removed[200005];
int mx_depth = 0;

// calculate all subtree size
void dfs1(int u, int p) {    
    sz[u] = 1;
    for (auto v : adj[u]) {
        if (v == p || removed[v]) continue;
        dfs1(v, u);
        sz[u] += sz[v]; 
    }
}

ll ans = 0;
// add to ans
void dfs2(int u, int p, int d, int k, int type) {
    if (type == 1) ans += cnt[k-d];
    if (type == 2) cnt[d]++;

    mx_depth = max(mx_depth, d);
    if (d == k) return;

    for (auto v : adj[u]) {
        if (v == p || removed[v]) continue;
        dfs2(v, u, d+1, k, type);
    }
}

int find_centroid(int u, int p, int n) {
    if (n == 1) return u;
    
    int mx_sz = 0, mx_id = -1;
    for (auto v : adj[u]) {
        if (v == p || removed[v]) continue;
        if (sz[v] > mx_sz) {
            mx_sz = sz[v];
            mx_id = v;
        }
    }

    if (mx_sz*2 > n) return find_centroid(mx_id, u, n);
    else return u;
}

void centroid_decompotition(int root, int k) {
    dfs1(root, 0);
    int centroid = find_centroid(root, 0, sz[root]);

    // process
    cnt[0] = 1; // root
    mx_depth = 0;
    removed[centroid] = true;
    for (auto v : adj[centroid]) {
        if (removed[v]) continue;
        dfs2(v, centroid, 1, k, 1); // increase ans   
        dfs2(v, centroid, 1, k, 2); // update cnt
    }
    // reset cnt
    for (int i = 0; i <= mx_depth; i++) cnt[i] = 0;

    for (auto v : adj[centroid]) {
        if (removed[v]) continue;
        centroid_decompotition(v, k);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

// inside main    
centroid_decompotition(1, k);
cout << ans << "\n";
    
    return 0;
}

/*
7 2
1 2
2 3
3 4
3 5
2 6
3 7

6 1
1 2
2 3
3 4
4 5
5 6

5 1
1 2
2 4
1 3
3 5
*/