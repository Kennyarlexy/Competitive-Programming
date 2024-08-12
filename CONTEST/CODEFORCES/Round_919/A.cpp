#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll n; cin >> n;

        ll l = LLONG_MIN, r = LLONG_MAX;

        vector<ll> V;
        for (int i = 1; i <= n; i++) {
            ll a, x; cin >> a >> x;
            if (a == 1) l = max(l, x);
            else if (a == 2) r = min(r, x);
            else V.push_back(x);
        }

        ll ans = r-l+1;
        for (int i = 0; i < V.size(); i++) {
            if (V[i] >= l && V[i] <= r) ans--;
        }

        cout << max(0LL, ans) << "\n";
    }
    
    return 0;
}