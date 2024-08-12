#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[105];

int main() {
    fast_io();
    //use ll when possible!
    ll B, N;
    while (true) {
        cin >> B >> N;
        if (B == 0 && N == 0) break;
        for (ll i = 1; i <= B; i++) {
            cin >> A[i];
        }

        for (ll i = 1; i <= N; i++) {
            ll D, C, V; cin >> D >> C >> V;
            A[D] -= V;
            A[C] += V;
        }

        bool OK = true;
        for (ll i = 1; i <= B; i++) {
            if (A[i] < 0) {
                OK = false;
                break;
            }
        }

        cout << (OK ? "S" : "N") << "\n";
    }

    return 0;
}