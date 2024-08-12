//WA
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[1005];

int main() {
    fast_io();
    //use ll when possible!
    ll N, M; cin >> N >> M;
    for (ll i = 1; i <= N; i++) {
        cin >> A[i];
    }

    sort(A + 1, A + N + 1, greater<ll>());
    ll res = -1;
    ll cnt = 0;
    for (ll i = 1; i <= N-2; i++) {
        if (A[i] - A[i+2] <= M) {
            cnt++;
            res = max(res, A[i] + A[i+1] + A[i+2]);
        }
    }
    if (cnt > 0) {
        cout << cnt << " " << res << "\n";
    } else {
        cout << "-1\n";
    }

    return 0;
}