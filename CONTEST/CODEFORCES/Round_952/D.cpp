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
        ll n, m; cin >> n >> m;
        ll a = LLONG_MAX, b = LLONG_MIN, c = LLONG_MAX, d = LLONG_MIN;
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= m; j++) {
                char ch; cin >> ch;
                if (ch == '#') {
                    a = min(a, i);
                    b = max(b, i);
                    c = min(c, j);
                    d = max(d, j);
                }
            }
        }

        ll x = (a + b) / 2;
        ll y = (c + d) / 2;

        cout << x << " " << y << "\n";
    }
    
    return 0;
}