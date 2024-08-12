#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

vector<ll> adj[200005];
ll cnt[200005];
set<pair<ll, ll>> PQ;
vector<ll> res;

void f(ll u) {
    PQ.erase({cnt[u], u});
    cnt[u] = 0;
    for (auto& v : adj[u]) {
        if (cnt[v] == 0) continue;
        if (cnt[v] == 1) PQ.erase({1, v});
        else {
            PQ.erase({cnt[v], v});
            PQ.insert({cnt[v]-1, v});
        }
        cnt[v]--;
    }
}

int main() {
    fast_io();
    //use ll when possible!
    ll n; cin >> n;
    for (ll i = 1; i < n; i++) {
        ll a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        cnt[a]++;
        cnt[b]++;
    }

    for (ll i = 1; i <= n; i++) {
        if (cnt[i] == 0) continue;
        PQ.insert({cnt[i], i});
    }

    while (!PQ.empty()) {
        auto top = *PQ.rbegin();
        res.push_back(top.se);
        f(top.se);
    }

    cout << res.size() << "\n";
    for (auto& d : res) {
        cout << d << " ";
    }
    cout << "\n";

    return 0;
}