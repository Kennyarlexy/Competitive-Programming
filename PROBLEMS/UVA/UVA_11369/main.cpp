#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[20005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        sort(A, A+n, greater<int>());
        int ans = 0;
        for (int i = 2; i < n; i+=3) {
            ans += A[i];
        }

        cout << ans << "\n";
    }
    
    return 0;
}