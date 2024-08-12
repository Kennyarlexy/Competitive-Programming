#include <bits/stdc++.h>
#define ll long long
using namespace std;

string A[1505], B[1505];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll M, N; cin >> M >> N;
        cin.ignore(1000, '\n');
        for (ll i = 1; i <= M; i++) {
            getline(cin, A[i]);
        }

        for (ll i = 1; i <= N; i++) {
            getline(cin, B[i]);
        }

        unordered_set<string> res;
        res.reserve(N*M);
        for (ll i = 1; i <= M; i++) {
            for (ll j = 1; j <= N; j++) {
                res.insert(A[i]+B[j]);
            }
        }

        cout << "Case " << t << ": " << res.size() << "\n";
    }
    
    return 0;
}