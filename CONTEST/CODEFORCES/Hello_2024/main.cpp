#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

vector<ll> A[2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        memset(A, 0, sizeof(A));
        A[0].push_back(LLONG_MAX);
        A[1].push_back(LLONG_MAX);

        ll mx = 1;
        for (int i = 1; i <= n; i++) {
            ll a; cin >> a;
            if (a <= A[1-mx].back()) A[1-mx].push_back(a);
            else if (a <= A[mx].back()) A[mx].push_back(a);
            else {
                A[1-mx].push_back(a);
                mx = 1-mx;
            }
        }

        ll ans = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j < A[i].size()-1; j++) {
                ans += (A[i][j] < A[i][j+1]);
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}