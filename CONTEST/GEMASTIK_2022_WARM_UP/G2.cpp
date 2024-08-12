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
    ll M = 1;
    ll dM = 1;

    ll dx[] = {0, 1, 0, -1};
    ll dy[] = {-1, 0, 1, 0};
    while (M <= 100000) {
        for (ll m = M; m <= min(100000LL, M + dM); m++) {
            X[m] = X[m-1] + dx[dM % 4];
            Y[m] = Y[m-1] + dy[dM % 4];
        }
        M += dM;
        dM++;
    }

    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll m; cin >> m;
        cout << X[m] << " " << Y[m] << "\n";
    }

    return 0;
}