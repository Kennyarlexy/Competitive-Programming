#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct UFDS {
    vector<ll> P, dist;

    UFDS(ll size) : P(size, -1), dist(size, 0) {};

    ll findSet(ll u) {
        if (P[u] == -1) return u;
    
        ll set = findSet(P[u]);
        dist[u] += dist[P[u]];
        return P[u] = set;
    }

    void joinSet(ll u, ll v) {
        if (u == v) return;
        P[u] = v;
        dist[u] = abs(u-v) % 1000;
    }

    ll getDist(ll u) {
        findSet(u);
        return dist[u];
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll N; cin >> N;

        UFDS uf(N+5);
        
        char cmd;
        while (true) {
            cin >> cmd;
            if (cmd == 'O') break;

            if (cmd == 'E') {
                ll i; cin >> i;
                cout << uf.getDist(i) << "\n";
            } else {
                ll i, j; cin >> i >> j;
                uf.joinSet(i, j);
            }
        }
    }
    
    return 0;
}