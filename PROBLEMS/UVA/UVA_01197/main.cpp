#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct UFDS {
    vector<ll> P, rank;

    UFDS(ll size) : P(size+5, -1), rank(size+5, 0) {}

    ll findSet(ll u) {
        if (P[u] == -1) return u;
        return P[u] = findSet(P[u]);
    }

    bool isSameSet(ll u, ll v) {
        return findSet(u) == findSet(v);
    }

    void unionSet(ll u, ll v) {
        if (isSameSet(u, v)) return;

        u = findSet(u);
        v = findSet(v);
        if (rank[u] > rank[v]) swap(u, v);
        if (rank[u] == rank[v]) rank[v]++;
        P[u] = v;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        UFDS uf(n);
        for (ll i = 1; i <= m; i++) {
            ll k; cin >> k;
            ll p; cin >> p;
            for (ll j = 2; j <= k; j++) {
                ll u; cin >> u;
                uf.unionSet(p, u);
            }
        }

        ll suspect = uf.findSet(0);
        ll res = 0;
        for (ll i = 0; i < n; i++) {
            if (uf.findSet(i) == suspect) res++;
        }
        cout << res << "\n";
    }
    
    return 0;
}