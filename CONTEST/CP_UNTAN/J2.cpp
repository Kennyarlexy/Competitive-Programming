#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

vector<ll> adj[200005];
bool vis[200005];
vector<ll> A;
vector<ll> B;

void dfs(ll u, ll dist) {
    if (vis[u]) return;

    vis[u] = true;
    if (dist % 2 == 0) A.push_back(u);
    else B.push_back(u);
    
    for (auto& v : adj[u]) {
        dfs(v, dist+1);
    }
}

int main() {
    fast_io();
    //use ll when possible!
    ll n; cin >> n;
    for (ll i = 1; i < n; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    
    if (A.size() < B.size()) {
        cout << A.size() << "\n";
        for (auto& d : A) {
            cout << d << " ";
        }
        cout << "\n";
    } else {
        cout << B.size() << "\n";
        for (auto& d : B) {
            cout << d << " ";
        }
        cout << "\n";
    }

    cout << A.size() << " " << B.size() << "\n";

    return 0;
}