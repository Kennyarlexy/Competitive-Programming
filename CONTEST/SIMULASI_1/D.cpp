#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

struct Edge {
    ll t;
    ll c;
    Edge(ll b, ll _c) {
        t = b, c = _c;
    }
};

bool vis1[1005];
bool vis2[1005];
vector<Edge>* adj;

bool dfs(ll u, ll sum = 0, ll prev = 0) {
    
    if (vis1[u]) {
        if (vis2[u] && sum > 0) {
            // cout << "Found a cycle\n";
            return true;
        } 
        return false;
    }

    // cout << "visiting " << u << "\n";
    vis1[u] = true;
    vis2[u] = true; //vis2 untuk memberi tanda node yang sedang ada dalam cycle SAAT INI
    for (auto& [v, c] : adj[u]) {
        // cout << u << " to " << v << " -> " << "c = " << c << " sum = " << sum + c << "\n";
        if (v == prev) continue;
        if (dfs(v, sum + c, u)) return true;
    }

    vis2[u] = false; //sudah backtracking
    return false;
}

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll n, m; cin >> n >> m;
        map<string, ll> MP;
        ll k = 0;
        adj = new vector<Edge>[1005];
        for (ll e = 1; e <= m; e++) {
            string u, v; cin >> u >> v;
            ll c; cin >> c;
            //hashing
            map<string, ll>::iterator it1, it2;
            bool in1, in2;
            tie(it1, in1) = MP.emplace(u, k);
            tie(it2, in2) = MP.emplace(v, k);
            if (in1) it1->second = ++k;
            if (in2) it2->second = ++k;
            //----------------
            adj[it1->second].emplace_back(it2->second, c);
        }        
        bool OK = false;
        for (ll u = 1; u <= n; u++) {
            memset(vis1, 0, sizeof(vis1));
            memset(vis2, 0, sizeof(vis2));
            // cout << "start = " << u << "\n";
            if (dfs(u)) {
                cout << "YA\n";
                OK = true;
                break;
            }
        }

        if (!OK) cout << "TIDAK\n";


        // debug hashing
        // for (auto& [tempat, node] : MP) {
        //     cout << tempat << " = " << node << "\n";
        // }
        // cout << "---------------------------------------\n";
    }

    return 0;
}