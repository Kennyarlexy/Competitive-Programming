#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

pair<ll, ll> A[1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll W, N; cin >> W >> N;
        for (ll i = 1; i <= N; i++) {
            cin >> A[i].fi >> A[i].se;
        }

        ll dist = 0;
        ll i = 1;
        while (i <= N) {
            ll w = A[i].se;
            while (i+1 <= N && w + A[i+1].se <= W) {
                w += A[i+1].se;
                i++;
            }

            if (w == W || i == N) dist += 2*A[i].fi;
            else dist += 2*A[i+1].fi;
            i++;
        }
        cout << dist << "\n";
    }
    
    return 0;
}