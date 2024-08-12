#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[30];

int main() {
    fast_io();
    //use ll when possible!
    ll n; cin >> n;
    ll total = 0;
    for (ll i = 0; i < n; i++) {
        cin >> A[i];
        total += A[i];
    }

    bool OK = false;
    for (ll i = 1; i < (1LL << n); i++) {
        ll sum = 0;
        for (ll j = 0; j < n; j++) {
            if (i & (1LL << j)) sum += A[j];
        }

        if (2*sum == total) {
            OK = true;
            cout << "YA\n";
            for (ll j = 0; j < n; j++) {
                if (i & (1LL << j)) {
                    cout << 1 << " ";
                } else {
                    cout << 2 << " ";
                }
            }
            cout << "\n";
            break;
        }
    }

    if (!OK) cout << "TIDAK\n";

    return 0;
}