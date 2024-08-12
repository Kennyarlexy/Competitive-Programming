#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N[5];
unordered_set<ll> all, A[5];
ll P[5], Q[5];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        for (ll i = 1; i <= 3; i++) {
            cin >> N[i];
            A[i] = {};
            A[i].reserve(N[i]);
        }

        all = {};
        all.reserve(N[1] + N[2] + N[3]);
        for (ll i = 1; i <= 3; i++) {
            for (ll j = 1; j <= N[i]; j++) {
                ll a; cin >> a;
                A[i].insert(a);
                all.insert(a);
            }
        }

        memset(P, 0, sizeof(P));
        memset(Q, 0, sizeof(Q));
        cout << "Case #" << t << ":\n";
        for (auto d : all) {
            ll k = A[1].count(d) + A[2].count(d) + A[3].count(d);


            if (k == 1) {
                for (ll i = 1; i <= 3; i++) {
                    if (A[i].count(d) == 1) {
                        P[i]++;
                        break;
                    }
                }
            } else if (k == 2) {
                for (ll i = 1; i <= 3; i++) {
                    if (A[i].count(d) == 0) {
                        Q[i]++;
                        break;
                    }
                }
            }
        }

        for (ll i = 1; i <= 3; i++) {
            cout << P[i] << " " << Q[i] << "\n";
        }
    }
    
    return 0;
}

/*
3
2 2 2
1 2
3 4
0 0
2 2 2
1 2
2 3
3 1
6 4 3
11 22 33 44 55 66
11 22 77 88
33 44 55
*/