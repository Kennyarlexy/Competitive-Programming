#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
// #define Point pair<ll, ll>
// #define x fi
// #define y se
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll mn_x = LLONG_MAX, mx_x = LLONG_MIN;
        ll mn_y = LLONG_MAX, mx_y = LLONG_MIN;
        for (int i = 1; i <= 4; i++) {
            ll x, y; cin >> x >> y;
            mn_x = min(mn_x, x);
            mx_x = max(mx_x, x);
            mn_y = min(mn_y, y);
            mx_y = max(mx_y, y);
        }
        ll ans = (mx_x-mn_x) * (mx_y-mn_y);
        cout << ans << "\n";
    }
    
    return 0;
}