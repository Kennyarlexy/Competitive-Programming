#include <bits/stdc++.h>
#define ll long long
using namespace std;


const ll INF = 1e14;
ll A[1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        A[n+1] = INF;
        int ans = 0;
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            if (sum + A[i] < A[i+1]) {
                sum += A[i];
                ans++;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}