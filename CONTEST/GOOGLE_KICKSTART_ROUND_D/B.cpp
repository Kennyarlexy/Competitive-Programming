#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[6005];
ll preA[6005];
ll maxA[6005];
ll B[6005];
ll preB[6005];
ll maxB[6005];

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        memset(maxA, 0, sizeof(maxA));
        memset(maxB, 0, sizeof(maxB));
        ll N; cin >> N;
        for (ll i = 1; i <= N; i++) {
            cin >> A[i];
        }
        ll M; cin >> M;
        for (ll i = 1; i <= M; i++) {
            cin >> B[i];
        }

        ll tempA = 0;
        for (ll i = 1; i <= N; i++) {
            tempA += A[i];
            preA[i] = tempA;
        }

        ll tempB = 0;
        for (ll i = 1; i <= M; i++) {
            tempB += B[i];
            preB[i] = tempB;
        }

        ll K; cin >> K;
        for (ll subA = 1; subA <= min(K, N); subA++) {
            for (ll nl = 0; nl <= subA; nl++) {
                ll nr = subA - nl;
                maxA[subA] = max(maxA[subA], preA[nl] + preA[N] - preA[N-nr]);
            }
        }

        for (ll subB = 1; subB <= min(K, M); subB++) {
            for (ll nl = 0; nl <= subB; nl++) {
                ll nr = subB - nl;
                maxB[subB] = max(maxB[subB], preB[nl] + preB[M] - preB[M-nr]);
            }
        }

        ll res = 0;
        for (ll subA = 0; subA <= min(N, K); subA++) {
            ll subB = K - subA;
            res = max(res, maxA[subA] + maxB[subB]);
        }

        cout << "Case #" << t << ": " << res << "\n";
    }

    return 0;
}