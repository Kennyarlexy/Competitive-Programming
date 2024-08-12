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
        ll mx = LLONG_MIN;
        ll ans = -1;
        for (int x = 2; x <= n; x++) {
            ll sum = 0;
            int i = 1;
            while (i*x <= n) {
                sum += i*x;
                i++;
            }

            if (sum > mx) {
                mx = sum;
                ans = x;
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}