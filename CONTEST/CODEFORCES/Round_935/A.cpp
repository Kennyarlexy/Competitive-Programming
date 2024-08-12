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
        ll a, b, c; cin >> a >> b >> c;
        if (c < (3 - b%3)%3) {
            cout << "-1\n";
        } else {
            ll x = (b+c) / 3;
            ll y = (b+c - x*3 + 2)/3;
            ll ans = a + x + y;
            cout << ans << "\n";
        }
    }
    
    return 0;
}