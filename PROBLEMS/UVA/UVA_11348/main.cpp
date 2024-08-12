#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll A[55];
struct stam {
    ll owner = 0;
    bool unique = true;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll N; cin >> N;
        unordered_map<ll, stam> MP;
        MP.reserve(50*N);
        for (ll i = 1; i <= N; i++) {
            ll M; cin >> M;
            for (ll j = 1; j <= M; j++) {
                ll a; cin >> a;
                if (MP.count(a)) {
                    if (i != MP[a].owner) MP[a].unique = false;
                } else {
                    MP[a].owner = i;
                }
            }
        }

        memset(A, 0, sizeof(A));
        ll total = 0;
        for (auto& d : MP) {
            if (d.se.unique) {
                total++;
                A[d.se.owner]++;
            }
        }

        double _total = total;
        cout << "Case " << t << ":";
        for (ll i = 1; i <= N; i++) {
            cout << fixed << setprecision(6) << " " << A[i] * 100 / _total << "%";
        }
        cout << "\n";
    }
    
    return 0;
}