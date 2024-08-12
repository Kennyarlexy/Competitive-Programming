#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[100005];
ll ans[250];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll N, Q; cin >> N >> Q;
        for (ll i = 1; i <= N; i++) {
            cin >> A[i];
        }

        memset(ans, 0, sizeof(ans));
        for (ll a = 0; a < 230; a++) {
            for (ll i = 1; i <= N; i++) {
                ans[a] = max(ans[a], a & A[i]);
            }
        }
        
        for (ll q = 1; q <= Q; q++) {
            ll a; cin >> a;
            cout << ans[a] << "\n";
        }
    }
    
    return 0;
}