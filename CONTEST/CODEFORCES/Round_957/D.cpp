#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

char A[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m, k; cin >> n >> m >> k;
        A[n+1] = 'L';
        for (int i = 1; i <= n; i++) cin >> A[i];

        int i = 0;
        bool OK = true;
        while (i <= n) {
            while (i+1 <= n && A[i+1] == 'L') i++;

            if (i > n) break;

            i++;
            int j = 1;
            while (A[i] != 'L' && j < m) {
                i++;
                j++;
            }

            while (A[i] == 'W' && k > 0) {
                i++;
                k--;
            }

            // cout << "k = " << k << "\n";
            if (A[i] != 'L') {
                OK = false;
                break;
            }
        }

        if (OK) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}