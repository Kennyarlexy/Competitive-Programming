#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll A[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        bool OK = true;
        for (int i = 1; i < n; i++) {
            ll mn = min(A[i], A[i+1]);
            A[i] -= mn;
            A[i+1] -= mn;
            if (A[i] != 0) {
                OK = false;
                break;
            }
        }

        if (OK) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}