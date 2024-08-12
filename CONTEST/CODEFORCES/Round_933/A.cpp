#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
#define Point pair<ll, ll>
using namespace std;

ll A[105], B[105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m, k; cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> B[i];
        }

        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (A[i] + B[j] <= k) ans++;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}