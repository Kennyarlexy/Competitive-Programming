#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[200005], B[200005];
ll PA[200005], PB[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m, Q; cin >> n >> m >> Q;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        for (int i = 1; i <= m; i++) {
            cin >> B[i];
        }

        sort(A + 1, A + n + 1, greater<ll>());
        sort(B + 1, B + m + 1, greater<ll>());
        for (int i = 1; i <= n; i++) {
            PA[i] = PA[i - 1] + A[i];
        }

        for (int i = 1; i <= m; i++) {
            PB[i] = PB[i - 1] + B[i];
        }

        for (int q = 1; q <= Q; q++) {
            int x, y, z; cin >> x >> y >> z;
            int j = min(z, y);
            int i = min(x, z - j);

            int k = 0; // total yang dicoret
            for (int step = n; step >= 1; step/=2) {
                while (i+k+step <= n && j-k-step+1 > 0 && i+k+step <= x && A[i+k+step] > B[j-k-step+1]) {
                    k += step;
                }
            }

            ll ans = PA[i+k] + PB[j-k];
            cout << ans << "\n";
        }
    }
    
    
    return 0;
}