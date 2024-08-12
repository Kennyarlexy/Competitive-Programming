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
        ll l = 2;
        ll X = 0;
        ll start;
        while (true) {
            ll add = (n + l/2) / l;
            X += add;
            if (X >= k) {
                X -= add;
                start = l/2;
                break;
            }

            l *= 2;
        }

        ll m = k - X;
        // cout << "start = " << start << " l = " << l << "\n";
        ll ans = start + (m-1)*l;
        cout << ans << "\n";
    }
    
    return 0;
}