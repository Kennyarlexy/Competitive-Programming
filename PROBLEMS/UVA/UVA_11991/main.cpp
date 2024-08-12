#include <bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<ll, vector<ll>> MP;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    while (cin >> n >> m) {
        MP = {};
        for (ll i = 1; i <= n; i++) {
            ll a; cin >> a;
            MP[a].push_back(i);
        }

        for (ll i = 1; i <= m; i++) {
            ll k, v; cin >> k >> v;
            if (k <= MP[v].size()) cout << MP[v][k-1] << "\n";
            else cout << "0\n";
        }
    }
    
    return 0;
}