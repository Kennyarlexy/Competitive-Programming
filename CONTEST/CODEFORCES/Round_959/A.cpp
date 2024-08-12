#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

int A[15][15];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m; cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> A[i][j];
            }
        }

        if (n == 1 && m == 1) {
            cout << "-1\n";
            continue;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                A[i][j]++;
                if (A[i][j] > n*m) A[i][j] = 1;
                cout << A[i][j] << " \n"[j==m];
            }
        }
    }
    
    return 0;
}