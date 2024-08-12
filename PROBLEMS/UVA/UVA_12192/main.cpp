#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool valid(ll i, ll j, ll N, ll M) {
    if (i >= N) return false;
    if (j >= M) return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, M;
    while (cin >> N >> M && N && M) {
        vector<vector<ll>> A(N, vector<ll> (M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }

        ll Q; cin >> Q;
        for (int q = 1; q <= Q; q++) {
            ll L, U; cin >> L >> U;
            ll ans = 0;
            for (int i = 0; i < N; i++) {            
                ll x = i;
                ll y = lower_bound(A[i].begin(), A[i].end(), L) - A[i].begin();
                if (y == M) continue;
                if (A[i][y] > U) continue;

                ll a = x, b = y;

                for (ll step = min(M, N); step > 0; step /= 2) {
                    while (valid(x+step, y+step, N, M) && A[x+step][y+step] <= U) {
                        x += step;
                        y += step;
                    }
                }

                ans = max(ans, x-a+1);
            }

            cout << ans << "\n";
        }

        cout << "-\n";
    }
    
    return 0;
}