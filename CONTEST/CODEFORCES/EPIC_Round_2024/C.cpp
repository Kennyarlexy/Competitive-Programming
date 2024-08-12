#include <bits/stdc++.h>
#define ll long long
#define se second 
#define fi first
using namespace std;

ll A[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        if (n == 1) {
            cout << A[1] << "\n";
            continue;
        }
        
        ll e = max(0LL, A[n] - (A[n-1] - 1));
        ll X = e;
        A[n] -= e;
        for (int i = n-1; i >= 2; i--) {
            if (A[i-1] > A[i]) {
                ll d = min(X, A[i-1] - A[i]);
                A[i-1] -= d;
            }

            ll y = max(0LL, A[i] - (A[i-1] - 1));
            X += y;
            A[i] -= y;
        }

        ll ans = X + A[1];
        cout << ans << "\n";
    }
    
    return 0;
}

/*
6
6
7 7 4 4 3 2
3
1 100 1000
2
100 1
2
1 100
2
1 1
3
7 4 8

*/