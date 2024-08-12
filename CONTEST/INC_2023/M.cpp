#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

// f() return minimum step to construct K

// ll f(ll N, ll M, ll K, ll check) {
//     if (K == 0 || N*M == K) return 0;
//     if (check == 0) return 1e9;
    
//     ll i = K/M; // slice vertical
//     ll sisa_v = K - i*M;

//     ll j = K/N; // slice horizontal
//     ll sisa_h = K - N*j;

//     ll res = 1 + min(f(N-i, M, sisa_v, i), f(N, M-j, sisa_h, j));

//     return res;
// }

ll f(ll N, ll M, ll K) {
    if (N == 0 || M == 0) return 1e9;
    if (K == 0 || N*M == K) return 0;

    // vertical slice
    ll i, j, K_v, K_h;
    if (K / M == 0) {
        i = N - 1;
    } else {
        i = K / M;
        K_v = K - i*M;
    }

    if (K / N == 0) {
        j = M - 1;
    } else {
        j = K / N;
        K_h = K - j*N;
    }

    ll res = 1 + min(f(N-i, M, K_v), f(N, M-j, K_h));
    return res;
}

int main() {
    fast_io();
    //use ll when possible!
    ll N, M, K; cin >> N >> M >> K;
    cout << f(N, M, K) << "\n";

    return 0;
}