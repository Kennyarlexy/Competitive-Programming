#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll m, a, b, c; cin >> m >> a >> b >> c;
        ll x = min(m, a);
        ll y = min(m, b);

        ll m1 = m, m2 = m;
        m1 -= x; m2 -= y;

        ll z = min(m1 + m2, c);

        ll ans = x + y + z;
        cout << ans << "\n";
    }
    
    return 0;
}