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
        if (k == 0) {
            cout << "0\n";
            continue;
        }
        
        k -= min(k, n);
        int ans = 1;

        for (ll i = n-1; i >= 1 && k > 0; i--) {
            k -= min(k, i);
            ans++;
            if (k == 0) break;
            k -= min(k, i);
            ans++;
        }

        cout << ans << "\n";
    }
    
    return 0;
}