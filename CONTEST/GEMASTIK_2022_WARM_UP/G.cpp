#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll X[100005];
ll Y[100005];

int main() {
    fast_io();
    //use ll when possible!

    ll dm = 0;
    
    for (ll m = 1; m <= 100000; m+=dm) {
        dm++;
        for (ll i = m; i < min(100000LL, m + dm); i++) {
            if (dm % 4 == 1) {
                X[i] = (X[i-1] + 1);
            } else if (dm % 4 == 2) {
                Y[i] = (Y[i-1] + 1);
            } else if (dm % 4 == 3) {
                X[i] = X[i-1] - 1;
            } else {
                Y[i] = Y[i-1] - 1;
            }
        }
    }
    
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll M; cin >> M;
        cout << X[M] << " " << Y[M] << "\n";
    }

    return 0;
}