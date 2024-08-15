#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

ll A[200005];
char B[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            A[i] += A[i-1];
        }

        int mn = n+1, mx = 0;
        vector<int> X, Y;
        for (int i = 1; i <= n; i++) {
            cin >> B[i];
            if (B[i] == 'L') X.push_back(i);
            else Y.push_back(i);
        }

        reverse(Y.begin(), Y.end());
        int m = min(X.size(), Y.size());

        ll ans = 0;
        for (int i = 0; i < m && X[i] < Y[i]; i++) {
            ans += A[Y[i]] - A[X[i]-1];
        }
        cout << ans << "\n";
    }
    
    return 0;
}