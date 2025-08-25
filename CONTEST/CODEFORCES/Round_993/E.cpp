#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;

        ll K = 1;
        ll ans = 0;
        while (K <= 1e9) {
            ll x_low = (l2 + K - 1) / K;
            ll x_high = r2 / K;

            x_low = max(l1, x_low);
            x_high = min(r1, x_high);

            ans += max(0LL, x_high - x_low + 1);

            K *= k;
        }

        cout << ans << "\n";
    }
    
    
    return 0;
}