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
        ll n; cin >> n;
        ll w = __bit_width(n);
        ll k = __builtin_popcountll(n);
        if (k == 1) {
            cout << "1\n";
            cout << n << "\n";
            continue;
        }

        vector<ll> ans; ans.push_back(n);
        for (ll i = 0; i < w; i++) {
            if ((n & (1LL << i)) == 0) continue;
            ans.push_back(n ^ (1LL << i));
        }

        ll m = ans.size();
        cout << m << "\n";
        for (ll i = m-1; i >= 0; i--) {
            cout << ans[i] << " \n"[i==0];
        }
    }
    
    return 0;
}