#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

struct UFDS {
    vector<int> p, sz;

    UFDS(int n) : p(n+5), sz(n+5, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int find(int u) {
        if (p[u] == u) return u;
        return p[u] = find(p[u]);
    }


    bool same(int u, int v) {
        return find(u) == find(v);
    }


    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (sz[u] < sz[v]) swap(u, v);
        p[v] = u;
        sz[u] += sz[v];
    }
};

pair<int, int> EL_1[200005], EL_2[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m1, m2; cin >> n >> m1 >> m2;

        UFDS set_1(n+5), set_2(n+5);
        for (int i = 1; i <= m1; i++) {
            int u, v; cin >> u >> v;
            set_1.unite(u, v);
            EL_1[i] = {u, v};
        }

        for (int i = 1; i <= m2; i++) {
            int u, v; cin >> u >> v;
            set_2.unite(u, v);
            EL_2[i] = {u, v};
        }

        int cnt = 0;
        for (int i = 1; i <= m1; i++) {
            if (!set_2.same(EL_1[i].fi, EL_1[i].se)) cnt++;
        }

        for (int i = 1; i <= m2; i++) {
            if (!set_1.same(EL_2[i].fi, EL_2[i].se)) {
                cnt++;
                set_1.unite(EL_2[i].fi, EL_2[i].se);
            }
        }

        cout << cnt << "\n";
    }
    
    return 0;
}