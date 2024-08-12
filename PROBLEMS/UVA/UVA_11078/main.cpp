#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[100005];
ll Min[100005];

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll N; cin >> N;
        for (ll i = 1; i <= N; i++) {
            cin >> A[i];
        }

        Min[N] = A[N];
        for (ll i = N-1; i >= 2; i--) {
            Min[i] = min(A[i], Min[i+1]);
        }

        ll res = LONG_LONG_MIN;
        for (ll i = 1; i < N; i++) {
            res = max(res, A[i] - Min[i+1]);
        }
        cout << res << "\n";
    }

    return 0;
}