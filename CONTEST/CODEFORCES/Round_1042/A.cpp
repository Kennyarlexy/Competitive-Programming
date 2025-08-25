#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int A[1005], B[1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        for (int i = 1; i <= n; i++) {
            cin >> B[i];
        }

        int X = 0;
        for (int i = 1; i <= n; i++) {
            if (A[i] > B[i]) {
                X += A[i] - B[i];
            }
        }
        int ans = X + 1;
        cout << ans << "\n";
    }
    
    return 0;
}