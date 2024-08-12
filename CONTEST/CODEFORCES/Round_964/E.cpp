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
    for (int i = 1; i <= 200000; i++) {
        A[i] = A[i/3] + 1;
        // A[i] += A[i-1];
// if (i < 100) cout << "i = " << i << " -->" << A[i] << "\n";
    }
// cout << "----------------------------\n";   

    for (int i = 2; i <= 200000; i++) {
        A[i] += A[i-1];
// if (i < 100) cout << "i = " << i << " -->" << A[i] << "\n";
    }
// cout << "\n";   


    for (int t = 1; t <= T; t++) {
        int l, r; cin >> l >> r;
        ll ans = (A[l] - A[l-1])*2 + A[r] - A[l];
        cout << ans << "\n";
    }
    
    return 0; 
}