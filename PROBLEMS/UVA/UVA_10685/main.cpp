#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct UFDS {
    vector<ll> P, rank, setSize;
    ll _max;

    UFDS(ll size) : P(size, -1), rank(size, 0), setSize(size, 1) {
        _max = 1;
    };
    
    ll findSet(ll u) {
        if (P[u] == -1) return u;
        return P[u] = findSet(P[u]);    
    }

    void uniteSet(ll u, ll v) {
        u = findSet(u);
        v = findSet(v);
        if (u == v) return;

        if (rank[u] > rank[v]) swap(u, v);
        else if (rank[u] == rank[v]) rank[v]++;
        P[u] = v;
        setSize[v] += setSize[u];
        _max = max(_max, setSize[v]);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll C, R;
    while (true) {
        cin >> C >> R;
        if (C == 0 && R == 0) break;
        unordered_map<string, ll> MP; MP.reserve(C+5);
        for (ll i = 1; i <= C; i++) {
            string s; cin >> s;
            MP[s] = i;
        }

        UFDS uf(C+5);
        for (ll i = 1; i <= R; i++) {
            string u, v; cin >> u >> v;
            uf.uniteSet(MP[u], MP[v]);
        }

        cout << uf._max << "\n";
    }
    
    return 0;
}