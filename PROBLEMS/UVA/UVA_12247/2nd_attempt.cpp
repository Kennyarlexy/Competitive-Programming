#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

bool used[55];

int main() {
    fast_io();
    //use ll when possible!
    ll A, B, C, X, Y;
    while (cin >> A >> B >> C >> X >> Y && A) {
        memset(used, 0, sizeof(used));
        used[A] = used[B] = used[C] = used[X] = used[Y] = true;
        
        ll P[] = {A, B, C};
        sort(P, P+3);

        bool OK = false;
        for (ll Z = 1; Z <= 52; Z++) {
            if (used[Z]) continue;
            ll Q[] = {X, Y, Z};
            sort(Q, Q+3);
            ll iP = 0, iQ = 0;
            ll P_win = 0;
            while (iP < 3 && iQ < 3) {
                if (P[iP] > Q[iQ]) {
                    P_win++;
                    iP++;
                    iQ++;
                } else {
                    iP++;
                }
            }
            if (P_win < 2) {
                cout << Z << "\n";
                OK = true;
                break;
            }
        }
        if (!OK) cout << "-1\n";
    }
    // cout << "no error\n";

    return 0;
}