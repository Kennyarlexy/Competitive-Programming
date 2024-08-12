#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

pair<ll, ll> A[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll n, s, m; cin >> n >> s >> m;
        for (int i = 1; i <= n; i++) {
            cin >> A[i].fi >> A[i].se;
        }

        bool OK = (A[1].fi >= s || m - A[n].se >= s);
        for (int i = 2; i <= n; i++) {
            if (A[i].fi - A[i-1].se >= s) OK = true;
        }
        if (OK) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0; 
}