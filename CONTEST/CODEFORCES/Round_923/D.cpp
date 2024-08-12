#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define LSOne(x) ((x) & (-x))
using namespace std;

int A[200005], L[200005], R[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        int len = 1;
        L[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (A[i] != A[i-1]) len = 1;
            else len++;
            L[i] = len;
        }

        len = 1;
        R[n] = 1;
        for (int i = n-1; i >= 1; i--) {
            if (A[i] != A[i+1]) len = 1;
            else len++;
            R[i] = len;
        }

        int Q; cin >> Q;
        for (int q = 1; q <= Q; q++) {
            int l, r; cin >> l >> r;
            if (R[l] + L[r] > r-l+1) {
                cout << "-1 -1\n";
            } else if (R[l] + L[r] == r-l+1) {
                cout << l+R[l]-1 << " " << r-L[r]+1 << "\n";
            } else {
                cout << l << " " << r-L[r] << "\n";
            }
        }
        if (t < T) cout << "\n";
    }
    
    return 0;
}