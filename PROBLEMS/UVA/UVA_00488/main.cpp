#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll A, f; cin >> A >> f;
        for (ll i = 1; i <= f; i++) {
            for (ll r = 1; r <= A; r++) {
                for (ll c = 1; c <= r; c++) {
                    cout << r;
                }
                cout << "\n";
            }

            for (ll r = A-1; r >= 1; r--) {
                for (ll c = 1; c <= r; c++) {
                    cout << r;
                }
                cout << "\n";
            }
            if (i < f) cout << "\n";
        }
        if (t < T) cout << "\n";
    }
    
    return 0;
}