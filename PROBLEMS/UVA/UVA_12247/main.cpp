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
        ll Q[] = {X, Y};
        ll iP = 0, iQ = 0;
        sort(P, P+3); sort(Q, Q+2);
        
        ll P_win = 0;
        while (iP < 3 && iQ < 2) {
            if (P[iP] > Q[iQ]) {
                P_win++;
                iP++;
                iQ++;
            } else {
                iP++;
            }
        }

        if (P_win < 2) {
            ll res = -1;
            ll mark = (P_win == 0 ? P[0] : P[1]);
            for (ll i = mark + 1; i <= 52; i++) {
                if (!used[i]) {
                    res = i;
                    break;
                }
            }
            cout << res << "\n";
        } else {
            cout << "-1\n";
        }

    }

    return 0;
}