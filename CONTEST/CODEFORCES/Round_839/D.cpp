#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[200005];

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll n; cin >> n;
        for (ll i = 1; i <= n; i++) {
            cin >> A[i];
        }

        bool sorted = true;
        for (ll i = 1; i < n; i++) {
            if (A[i] > A[i+1]) {
                sorted = false;
                break;
            }
        }

        if (sorted) {
            cout << "0\n";
            continue;
        }

        ll x = -1;
        for (ll i = 1; i < n; i++) {
            if (A[i] < A[i+1]) {
                x = (A[i] + A[i+1]) / 2;
                break;
            } else if (A[i] > A[i+1]) {
                x = (A[i] + A[i+1] + 1) / 2;
                break;
            }
        }
        if (x == -1) cout << "-1\n";
        else {
            for (ll i = 1; i <= n; i++) {
                A[i] = abs(A[i] - x);
            }

            bool OK = true;
            for (ll i = 1; i < n; i++) {
                if (A[i] > A[i+1]) {
                    OK = false;
                    break;
                }
            }

            if (OK) cout << x << "\n";
            else cout << "-1\n";
        }
    }

    return 0;
}