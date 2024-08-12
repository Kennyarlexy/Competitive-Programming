#include <bits/stdc++.h>
#define ll long long
#define se second 
#define fi first
using namespace std;

ll A[100005], B[100005], C[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            B[i] = A[i];
        }
        if (n == 1) {
            cout << "0\n";
            continue;
        }
        
        for (int i = 2; i <= n; i++) B[i] = max(B[i], B[i-1]);

        ll mx = LLONG_MIN;
        ll X = 0;
        for (int i = 1; i <= n; i++) {
            mx = max(mx, B[i] - A[i]);
            X += B[i] - A[i];
        }

        ll ans = mx + X;
        cout << ans << "\n";
    }
    
    return 0;
}

/*
2
7
5 1 3 2 4 2 1
7
5 1 3 2 4 2 1
*/