#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

ll A[105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        for (int i = 2; i <= n; i++) {
            ll k = (A[i-1] + A[i]) / A[i];
            A[i] *= k;
        }

        cout << A[n] << "\n";
    }
    
    return 0;
}