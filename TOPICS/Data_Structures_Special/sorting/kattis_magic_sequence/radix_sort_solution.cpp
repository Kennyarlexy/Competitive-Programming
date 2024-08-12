/*
visit page 61 on CP 4 book 1, this is heavily optimized to reduce even some O(1) operation (though can be better). the idea is to do radix sort twice:
1. radix sort based on last 4 digits, (0 <= num < 10000)
2. radix sort based on first 5 digits, (0 <= num <= 100000)
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll S[2][1000005];
ll F[100005];


int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll N, A, B, C, X, Y;
        cin >> N >> A >> B >> C >> X >> Y;
        S[0][0] = A;

        for (ll i = 1; i < N; i++) {
            S[0][i] = (S[0][i-1]*B + A) % C;
        }
        
        memset(F, 0, sizeof(ll)*10000);
        for (ll i = 0; i < N; i++) {
            F[S[0][i]%10000]++;
        }

        for (ll i = 1; i < 10000; i++) {
            F[i] += F[i-1];
        }

        for (ll i = N-1; i >= 0; i--) {
            ll num = S[0][i] % 10000;
            S[1][F[num]-1] = S[0][i];
            F[num]--;
        }

        memset(F, 0, sizeof(F));
        for (ll i = 0; i < N; i++) {
            F[S[1][i]/10000]++;
        }

        for (ll i = 1; i <= 100000; i++) {
            F[i] += F[i-1];
        }

        for (ll i = N-1; i >= 0; i--) {
            ll num = S[1][i] / 10000;
            S[0][F[num]-1] = S[1][i];
            F[num]--;
        }

        ll V = 0;
        for (ll i = 0; i < N; i++) {
            V = (V*X + S[0][i]) % Y;
        }

        cout << V << "\n";
    }

    return 0;
}