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
        int n, k; cin >> n >> k;

        int ans = 0;
        while (n > 1) {
            n -= min(n, k-1);
            ans++;
        }
        cout << ans << "\n";
    }
    
    return 0;
}