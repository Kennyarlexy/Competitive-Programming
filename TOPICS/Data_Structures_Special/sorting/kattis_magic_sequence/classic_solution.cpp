#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll S[1000005];

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll N, A, B, C, X, Y;
        cin >> N >> A >> B >> C >> X >> Y;
        S[0] = A;
        
        for (ll i = 1; i < N; i++) {
            S[i] = (S[i-1]*B+A) % C;
        }

        sort(S, S+N);
        ll V = 0;
        for (ll i = 0; i < N; i++) {
            V = (V*X + S[i]) % Y;
        }
        cout << V << "\n";
    }

    return 0;
}