#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second 

using namespace std;

int A[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        
        int L = 1;
        for (int i = 2; i <= n; i++) {
            if (A[i] == A[i-1]) L++;
            else break;
        }

        int R = 1;
        for (int i = n-1; i >= 1; i--) {
            if (A[i] == A[i+1]) R++;
            else break;
        }

        if (A[1] == A[n]) {
            ll ans = max(0, n-L-R);
            cout << ans << "\n";
        } else {
            ll ans = n - max(L, R);
            cout << ans << "\n";
        }
    }
    
    return 0;
}