#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct UFDS {
    vector<int> p, sz;

    // n elements from [0..n-1]
    UFDS(int n) : p(n+5), sz(n+5, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int find(int u) {
        if (p[u] == u) return u;
        return p[u] = find(p[u]);
    }

    // returns true if u and v belong to the same set (have the same representative)
    bool same(int u, int v) {
        return find(u) == find(v);
    }

    // combine set u and v where sz[u] > sz[v] with u as the new representative 
    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (sz[u] < sz[v]) swap(u, v);
        p[v] = u;
        sz[u] += sz[v];
    }
};