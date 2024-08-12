#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

char A[1005][1005];
pair<int, int> B[1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, Q; cin >> n >> m >> k >> Q;
    
    int x = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
            if (A[i][j] == 'X') B[x++] = {i, j};
        }
    }

    for (int q = 1; q <= Q; q++) {
        int a, b; cin >> a >> b;
        int mn = INT_MAX;
        for (int i = 1; i <= k; i++) {
            mn = min(mn, abs(B[i].fi - a) + abs(B[i].se - b));
        }

        cout << mn << "\n";
    }
    
    return 0;
}