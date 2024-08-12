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
        ll x, y, k; cin >> x >> y >> k;
        ll z = (x + y - 1) / y * y;

        x += min(k, z-x);
        k -= min(k, z-x);
        
        while (k > 0 && x > 1) {
            
        }
    }
    
    return 0;
}