#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second 
using namespace std;

int A[55];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        int l = -1, r = -1;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            if (A[i] == 1 && l == -1) l = i;
            if (A[i] == 1) r = i;
        }

        int ans = 0;
        for (int i = l; i <= r; i++) {
            if (A[i] == 0) ans++;
        }
        cout << ans << "\n";
    }
    
    return 0;
}