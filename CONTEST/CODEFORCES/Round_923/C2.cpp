#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define LSOne(x) ((x) & (-x))
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m, k; cin >> n >> m >> k;
        map<int, bool> A, B;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            A[x] = true;
        }

        for (int i = 1; i <= m; i++) {
            int x; cin >> x;
            B[x] = true;
        }

        bool ans = true;
        int x = 0, y = 0, z = 0;
        for (int i = 1; i <= k; i++) {
            if (A[i] && B[i]) z++;
            else if (A[i]) x++;
            else if (B[i]) y++;
            else {
                ans = false;
                break;
            }
        }

        if (ans && z >= abs(x-y)) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}