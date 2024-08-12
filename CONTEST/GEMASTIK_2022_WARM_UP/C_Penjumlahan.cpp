#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[10005][10005];

int main() {
    fast_io();
    //use ll when possible!
    ll N, M, Q; cin >> N >> M >> Q;
    for (ll r = 1; r <= N; r++) {
        for (ll c = 1; c <= M; c++) {
            cin >> A[r][c];
        }
    }

    for (ll r = 1; r <= N; r++) {
        for (ll c = 2; c <= M; c++) {
            A[r][c] += A[r][c-1];
        }
    }

    for (ll c = 1; c <= M; c++) {
        for (ll r = 2; r <= N; r++) {
            A[r][c] += A[r-1][c];
        }
    }

    for (ll q = 1; q <= Q; q++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll res = A[x2][y2] - A[x2][y1-1] - A[x1-1][y2] + A[x1-1][y1-1];
        cout << res << "\n";
    }

    return 0;
}