#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll N, M; cin >> N >> M;

        unordered_map<ll, ll> A; A.reserve(N);
        unordered_map<ll, ll> B; B.reserve(M);
        unordered_set<ll> S; S.reserve(N+M);
        for (ll i = 1; i <= N; i++) {
            ll a; cin >> a;
            A[a]++;
            S.insert(a);
        }

        for (ll i = 1; i <= M; i++) {
            ll b; cin >> b;
            B[b]++;
            S.insert(b);
        }

        ll res = 0;
        for (auto& d : S) {
            res += abs(A[d] - B[d]);
        }
        cout << res << "\n";
    }
    
    return 0;
}