#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll A[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll n, l, r; cin >> n >> l >> r;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        int x = 1, y = 0;
        ll z = 0;
        ll ans = 0;
        while (x <= n && y <= n) {
            while (y < n && z < l) z += A[++y];
            while (x <= n && z > r) z -= A[x++];

            if (z >= l && z <= r) {
                z = 0;
                x = y+1;
                ans++;
            }
            z += A[++y];
        }

        cout << ans << "\n";
    }
    
    return 0;
}