#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[55][55];

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll n; cin >> n;
        ll a = 1;
        ll d = n*n-1;
        ll i = 0;
        A[1][1] = 1;
        for (ll r = 1; r <= n; r++) {
            if (r % 2 == 1) {
                for (ll c = 1; c <= n; c++) {
                    if (r == 1 && c == 1) continue;
                    i++;
                    if (i % 2 == 1) {
                        A[r][c] = a + d;
                    } else {
                        A[r][c] = a - d;
                    }
                    a = A[r][c];
                    d--;
                }
            } else {
                for (ll c = n; c >= 1; c--) {
                    if (r == 1 && c == 1) continue;
                    i++;
                    if (i % 2 == 1) {
                        A[r][c] = a + d;
                    } else {
                        A[r][c] = a - d;
                    }
                    a = A[r][c];
                    d--;
                }
            }
        }

        for (ll r = 1; r <= n; r++) {
            for (ll c = 1; c <= n; c++) {
                cout << A[r][c] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}