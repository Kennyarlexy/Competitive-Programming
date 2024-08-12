#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

int A[105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        sort(A+1, A+n+1);
        ll ans = 0;
        for (int i = 2; i <= n; i++) {
            ans += (A[i] - A[i-1]);
        }
        cout << ans << "\n";
    }
    
    return 0;
}