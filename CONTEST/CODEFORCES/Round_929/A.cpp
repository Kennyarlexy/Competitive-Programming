#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

ll A[55];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }   

        // sort(A+1, A+1+n);
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            if (A[i] < 0) A[i] = -A[i];
            ans += A[i];
        }
        cout << ans << "\n";
    }
    
    return 0;
}