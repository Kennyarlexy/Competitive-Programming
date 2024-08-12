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
    for (int t = 1; t <= T; t++) {
        ll N; cin >> N;
        for (ll i = 1; i <= N; i++) {
            cin >> A[i];
        }

        for (ll i = N-1; i >= 2; i--) {
            if (A[i] > A[i+1]) {
                ll d = A[i] - A[i+1];
                A[i] -= d;
                A[i-1] -= d;
            }
        }

        if (A[1] > A[2]) {
            cout << "TIDAK\n";
        } else {
            cout << "YA\n";
        }
    }

    return 0;
}