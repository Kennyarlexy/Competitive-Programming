#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

char A[1005][1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, k; cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> A[i][j];
            }
        }

        for (int i = 1; i+k-1 <= n; i += k) {
            for (int j = 1; j+k-1 <= n; j += k) {
                cout << A[i][j];
            }
            cout << "\n";
        }
    }
    
    return 0;
}