#include <bits/stdc++.h>
#define ll long long
using namespace std;

string A[105];
ll L[105];
ll R[105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n; cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> A[i];
    }

    ll il = -1e9;
    for (ll i = 1; i <= n; i++) {
        if (A[i] == "?") {
            L[i] = i-il;
        } else {
            il = i;
        }
    }

    ll ir = 1e9;
    for (ll i = n; i >= 1; i--) {
        if (A[i] == "?") {
            R[i] = ir-i;
        } else {
            ir = i;
        }
    }

    ll Q; cin >> Q;
    for (ll q = 1; q <= Q; q++) {
        ll i; cin >> i;
        if (A[i] == "?") {
            if (L[i] < R[i]) {
                for (ll j = 1; j <= L[i]; j++) {
                    cout << "right of ";
                }
                cout << A[i-L[i]] << "\n";
            } else if (R[i] < L[i]) {
                for (ll j = 1; j <= R[i]; j++) {
                    cout << "left of ";
                }
                cout << A[i+R[i]] << "\n";
            } else {
                cout << "middle of " << A[i-L[i]] << " and " << A[i+R[i]] << "\n";
            }
        } else {
            cout << A[i] << "\n";
        }
    }
    
    return 0;
}