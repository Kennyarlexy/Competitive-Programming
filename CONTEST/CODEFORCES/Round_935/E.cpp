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
        ll n, x; cin >> n >> x;
        int j = -1;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            if (A[i] == x) j = i;
        }

        int l = 1, r = n+1;
        while (r-l > 1) {
            int m = (l+r)/2;
            if (A[m] <= x) l = m;
            else r = m;
        }

        if (j == l) {
            cout << "0\n";
        } else {
            cout << "1\n";
            cout << j << " " << l << "\n";
        }
    }
    
    return 0;
}