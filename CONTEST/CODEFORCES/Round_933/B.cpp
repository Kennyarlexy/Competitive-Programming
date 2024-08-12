#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
#define Point pair<ll, ll>
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

        bool f = true;
        for (int i = 2; i <= n-1; i++) {
            ll d = min(A[i]/2, A[i-1]);
            A[i-1] -= d;
            A[i] -= d*2;
            A[i+1] -= d;
            if (A[i-1] != 0) {
                f = false;
                break;
            }
        }
        if (f && A[n-1] == 0 && A[n] == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}