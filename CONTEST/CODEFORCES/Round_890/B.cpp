#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[100005];

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll n; cin >> n;
        for (ll i = 0; i < n; i++) {
            cin >> A[i];
        }

        if (n == 1) {
            cout << "NO\n";
        } else {
            ll sum_1 = 0;
            for (ll i = 0; i < n-1; i++) {
                if (A[i] == 1) sum_1--;
                else {
                    sum_1 += (A[i]-1);
                }
            }

            if (sum_1 == 0 && A[n-1] == 1) cout << "NO\n";
            else if (A[n-1] + sum_1 > 0) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}