#include <bits/stdc++.h>
#define ll long long
#define se second 
#define fi first
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll n, k; cin >> n >> k;
        ll ans = (n - 1) * k + 1;
        cout << ans << "\n";
    }
    
    return 0;
}