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
        ll n, k; cin >> n >> k;
        memset(A, 0, sizeof(ll)*n + 5);

        ll _min = 1;
        ll _max = n;
        for (ll i = 1; i+2*k-2 <= n; i+=2*k-1) {
            A[i+k-1] = _min++;
        }

        for (ll i = 1; i <= n; i++) {
            if (A[i] != 0) continue;
            A[i] = _max--;
        }

        for (ll i = 1; i <= n; i++) {
            cout << A[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}