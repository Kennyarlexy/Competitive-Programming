#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[100];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        cin >> A[1] >> A[2] >> A[3];
        sort(A+1, A+4, greater<ll> ());
        if (A[1] + A[2] >= 10) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}