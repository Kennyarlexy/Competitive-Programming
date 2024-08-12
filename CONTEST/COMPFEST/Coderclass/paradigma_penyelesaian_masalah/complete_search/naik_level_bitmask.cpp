#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[25];

int main() {
    fast_io();
    //use ll when possible!
    ll N, M; cin >> N >> M;
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    bool OK = false;
    for (ll i = 1; i < (1 << N); i++) {
        ll sum = 0;
        for (ll j = 0; j < N; j++) {
            if (i & (1 << j)) sum += A[j];
        }

        if (sum == M) {
            OK = true;
            break;
        }
    }
    if (OK) cout << "bisa\n";
    else cout << "tidak bisa\n";

    return 0;
}