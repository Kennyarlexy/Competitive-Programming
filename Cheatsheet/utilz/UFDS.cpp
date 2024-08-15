#include <bits/stdc++.h>
#define ll long long
using namespace std;

//for union find
ll link[300005];
ll sz[300005];

// Method -> find(), same(), unite()
// returns the representative of u
ll find(ll u) {
    if (link[u] == u) return u;
    return link[u] = find(u);
}

// returns true if u and v belong to the same set (have the same representative)
bool same(ll u, ll v) {
    return find(u) == find(v);
}

// combine set u and v where sz[u] > sz[v] with u as the new representative 
void unite(ll u, ll v) {
    u = find(u);
    v = find(v);
    if (sz[u] < sz[v]) swap(u, v);
    link[v] = u;
    sz[u] += sz[v];
}