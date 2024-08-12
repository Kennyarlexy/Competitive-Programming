#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second 
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll n, k; cin >> n >> k;

        map<ll, multiset<ll>> MP;
        multiset<ll> all;
        for (int i = 1; i <= n; i++) {
            ll x; cin >> x;
            all.insert(x);
            MP[x % k].insert(x);
        }

        if (n == 1) {
            cout << "0\n";
            continue;
        }

        ll cnt = 1 - n%2; 
        ll ans = 0;
        while (all.size() > (cnt ? 0 : 3)) {
            ll x = *all.rbegin(); all.erase(all.find(x));

            auto &S = MP[x % k];
            S.erase(S.find(x));

            auto itr_2 = S.upper_bound(x);
            if (itr_2 == S.begin()) {
                cnt++;
            } else {
                --itr_2;
                ll y = *itr_2;
                ans += (x - y) / k;
                all.erase(all.find(y));
                S.erase(itr_2);
            }
        }

        if (cnt > 1) cout << "-1\n";
        else if (cnt == 1) {
            cout << ans << "\n";
        } else {
            vector<ll> V;
            for (auto x : all) V.push_back(x);

            assert(V.size() == 3);

            ll mn = LLONG_MAX;
            bool OK = false;
            for (int i = 0; i < 3; i++) {
                for (int j = i+1; j < 3; j++) {
                    ll x = abs(V[i] - V[j]);
                    if (x % k == 0) {
                        mn = min(mn, x/k);
                        OK = true;
                    }
                }
            }

            if (!OK) cout << "-1\n";
            else cout << ans + mn << "\n";
        }
    }
    
    return 0;
}