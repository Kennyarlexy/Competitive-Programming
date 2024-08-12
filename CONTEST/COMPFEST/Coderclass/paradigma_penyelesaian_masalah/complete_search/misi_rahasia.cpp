#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

bool adj[25][25];

int main() {
    fast_io();
    //use ll when possible!
    ll N, M; cin >> N >> M;
    for (ll e = 1; e <= M; e++) {
        ll u, v; cin >> u >> v;
        adj[u][v] = adj[v][u] = true;
    }

    ll res = 1;
    for (ll i = 1; i < (1LL << N); i++) {
        ll onBit = __builtin_popcount(i);
        if (onBit <= res) continue;

        vector<ll> V;
        for (ll j = 0; j < N; j++) {
            if (i & (1LL << j)) V.push_back(j+1);
        }

        bool complete = true;
        for (ll u = 0; u < V.size(); u++) {
            for (ll v = u + 1; v < V.size(); v++) {
                if (!adj[V[u]][V[v]]) {
                    complete = false;
                    goto exit;
                }
            }
        }

        exit:
        if (complete) res = onBit;
    }
    cout << res << "\n";

    return 0;
}