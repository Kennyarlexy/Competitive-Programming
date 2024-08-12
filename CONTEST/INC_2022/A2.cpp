//AC
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

    ll res = -1;
    ll cnt = 0;
    for (ll i = 1; i <= N; i++) {
        for (ll j = i+1; j <= N; j++) {
            for (ll k = j+1; k <= N; k++) {
                ll sum = A[i] + A[j] + A[k];
                ll Max = max(A[i], max(A[j], A[k]));
                ll Min = min(A[i], min(A[j], A[k]));
                if (Max - Min <= M) {
                    cnt++;
                    res = max(res, sum);
                }
            }
        }
    }
    if (cnt > 0) cout << cnt << " " << res << "\n";
    else cout << "-1\n";

    return 0;
}