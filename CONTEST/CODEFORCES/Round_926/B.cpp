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
        ll make = min(k, 4*n-4);
        k -= make;
        ll ans = (make+1) / 2 + max(0LL, k);
        cout << ans << "\n";
    }
    
    return 0;
}