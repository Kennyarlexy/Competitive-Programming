#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll A[105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= 2*n; i++) {
            cin >> A[i];
        }

        sort(A+1, A+(2*n)+1);
        ll ans = 0;
        for (int i = 1; i <= 2*n; i+=2) {
            ans += A[i];
        }
        cout << ans << "\n";
    }
    
    return 0;
}