#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

ll A[100005], B[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        B[1] = A[1] % 2;

        for (int i = 2; i <= n; i++) {
            B[i] = B[i-1] + (A[i] % 2);
            A[i] += A[i-1];
        }

        cout << A[1] << " ";
        for (int i = 2; i <= n; i++) {
            ll ans = A[i] - (B[i] / 3);

            if (B[i] % 3 == 1) ans--;
            cout << ans << " ";
        }
        cout << "\n";
    }
    
    return 0;
}