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
        int n, m; cin >> n >> m;
        string a, b; cin >> a >> b;
        // int i = 0, j = 0;
        int ans = 0;
        // while (i < n && j < m) {
        //     while (j+1 < m && a[i] != b[j]) j++;
        //     if (j == m && a[i] != b[j]) break;
        //     ans++;
        //     i++; j++;
        // }
        int j = 0;
        for (int i = 0; i < n && j < m; i++) {
            bool f = true;
            while (a[i] != b[j]) {
                j++;
                if (j == m) {
                    f = false;
                    break;
                } 
            }
            if (!f) break;
            ans++;
            j++;
        }

        cout << ans << "\n";
    }
    
    return 0;
}