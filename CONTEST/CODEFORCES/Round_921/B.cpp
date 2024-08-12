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
        int x, n; cin >> x >> n;
        if (n == 1) {
            cout << x << "\n";
            continue;
        }
        
        int ans = 1;
        for (int g = 2; g*g <= x; g++) {
            if (x % g != 0) continue;

            int f1 = g;
            int f2 = x/f1;
            int sigma_k_1 = x/f1;
            int sigma_k_2 = x/f2;
            if (sigma_k_1 >= n) ans = max(f1, ans);
            if (sigma_k_2 >= n) ans = max(f2, ans);
        }
        cout << ans << "\n";
    }
    
    return 0;
}