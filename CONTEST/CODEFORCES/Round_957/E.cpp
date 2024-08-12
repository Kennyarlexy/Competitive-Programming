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

        string s1 = to_string(n);
        ll k = s1.length();

        string s2;
        for (int i = 1; i <= 7; i++) s2 += s1;
        
        ll ans = 0;
        vector<pair<ll, ll>> res;
        for (ll a = 1; a <= 10000; a++) {
            for (ll d = 1; d <= 6; d++) {
                ll b = a*k - d;
                if (b > min(10000LL, a*n) || b < 1) continue;

                ll x1 = a*n - b;
                ll x2 = stoll(s2.substr(0, d));
                if (x1 == x2) {
                    ans++;
                    res.push_back({a, b});
                }
            }
        }

        cout << ans << "\n";
        for (int i = 0; i < ans; i++) {
            cout << res[i].fi << " " << res[i].se << "\n";
        }
    }
    
    return 0;
}