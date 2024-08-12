#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll n; cin >> n;
        map<ll, ll> f;
        for (ll i = 1; i <= n; i++) {
            ll a; cin >> a;
            f[a]++;
        }

        vector<ll> F;
        for (auto& [a, freq] : f) {
            F.push_back(freq);
        }

        sort(F.begin(), F.end());
        ll usable = f.size();
        ll res = F[0] * max(0LL, usable-2); //we can form F[0] amount of sequence sconsisting of f.size() or currently usable elements
        for (ll i = 1; i < F.size(); i++) {
            usable--;
            res += (F[i] - F[i-1]) * max(0LL, usable-2);
            //we can form F[i] amount of sequence consisting of currently usable elements
        }
        cout << res << "\n";
    }

    return 0;
}