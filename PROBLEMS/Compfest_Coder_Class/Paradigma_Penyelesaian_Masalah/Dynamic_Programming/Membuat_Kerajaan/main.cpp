#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[105][105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
            if (j > 1) A[i][j] += A[i][j-1];
        }
    }


    ll mx = LLONG_MIN;
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            ll X = LLONG_MIN;
            for (int k = 1; k <= n; k++) {
                ll Y = A[k][j];
                if (i > 1) Y -= A[k][i-1];
                if (X + Y > Y) X += Y;
                else X = Y;

                mx = max(mx, X);
            }
        }
    }

    cout << mx << "\n";
    
    return 0;
}