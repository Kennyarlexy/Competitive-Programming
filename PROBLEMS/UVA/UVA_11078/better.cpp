#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[100005];

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll N; cin >> N;
        for (ll i = 1; i <= N; i++) {
            cin >> A[i];
        }
        ll res = LONG_LONG_MIN;
        ll Max = A[1];
        for (ll i = 2; i <= N; i++) {
            res = max(res, Max - A[i]);
            Max = max(Max, A[i]);
        }
        cout << res << "\n";
    }

    return 0;
}