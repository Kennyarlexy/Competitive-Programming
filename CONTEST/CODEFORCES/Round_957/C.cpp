#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m, k; cin >> n >> m >> k;
        for (int i = n; i >= m+1; i--) {
            cout << i << " ";
        }

        for (int i = 1; i <= m; i++) {
            cout << i << " ";
        }
        cout << "\n";
    }
    
    return 0;
}