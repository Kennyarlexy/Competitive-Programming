#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[300005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        int hi = INT_MAX, lo = INT_MAX;
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            if (A[i] > A[i-1]) lo = min(lo, A[i-1]);
            if (A[i] > lo) hi = min(hi, A[i]);
            if (A[i] > lo && A[i] <= hi) ans++;
        }
        cout << ans << "\n";
    }
    
    return 0;
}