#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll S[1005];
ll D[1005];
ll F[1005];

int main() {
    fast_io();
    //use ll when possible!
    ll N;
    while (true) {
        cin >> N;
        if (N == 0) break;

        memset(F, -1, sizeof(F));
        for (ll i = 1; i <= N; i++) {
            cin >> S[i] >> D[i];
        }

        bool OK = true;
        for (ll i = 1; i <= N; i++) {
            ll iF = i + D[i];
            if (iF < 1 || iF > N || F[iF] != -1) {
                OK = false;
                break;
            }
            F[iF] = S[i]; 
        }

        if (OK) {
            for (ll i = 1; i <= N; i++) {
                cout << F[i];
                if (i < N) cout << " ";
            }
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}