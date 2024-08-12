#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        ll k, x, a; cin >> k >> x >> a;
        A[1] = 1;
        a -= 1;
        bool ans = true;
        for (int i = 2; i <= x+1; i++) {
            ll y = (A[i-1]) / (k-1) + 1;
        
            if (y > a) {
                ans = false;
                break;
            }
            a -= y;
            A[i] = y + A[i-1];
        }
        cout << (ans ? "YES":"NO") << "\n";
    }
    
    return 0;
}