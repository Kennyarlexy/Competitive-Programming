#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[10005];

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll N, M; cin >> N >> M;
        for (ll i = 1; i <= N; i++) {
            cin >> A[i];
        }

        sort(A + 1, A + N + 1, greater<int>());
        double res = 0;

        for (ll i = 1; i < M; i++) {
            res += A[i];
        }

        
        if ((N - M + 1) % 2 == 1) {
            ll im = (M + N) / 2;
            res += A[im];
        } else {
            ll iml = (M + N) / 2;
            ll imr = iml + 1;
            res += (A[iml] + A[imr]) / 2.0;
        }
        cout << "Case #" << t << ": " << fixed << setprecision(9) << res << "\n";
    }

    return 0;
}