#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

ll A[200005], X[200005];
const double log_2 = log(2);
const double EPS = 1e-10;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);    
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) cin >> A[i];

        X[1] = 0;
        ll ans = 0;
        bool OK = true;
        for (int i = 2; i <= n; i++) {
            if (A[i] == 1 && A[i-1] != 1) {
                OK = false;
                break;
            }

            if (A[i] == A[i-1]) {
                X[i] = X[i-1];
            } else {
                // X[i] = max(0.0, ceil((X[i-1]*log_2 + log(log(A[i-1])) - log(log(A[i]))) / log_2));
                double Y = (X[i-1]*log_2 + log(log(A[i-1])) - log(log(A[i]))) / log_2;
                if (Y <= 0) {
                    X[i] = 0;
                } else {
                    X[i] = ((ll) Y + EPS < Y) ? (ll) Y + 1 : (ll) Y;
                }                
            }

            ans += X[i];
// cout << "X[" << i << "] = " << X[i] << "\n";
        }
        
        if (OK) cout << ans << "\n";
        else cout << "-1\n";
    }
    
    return 0;
}

/*
1
9
16 2 4 2 256 2 4 2 8

1
3
3 1 5
*/