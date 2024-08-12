#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

int A[200005];
pair<ll, ll> B[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll n, m, h; cin >> n >> m >> h;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> A[j];
            }

            sort(A+1, A+m+1);
            ll time = 0;
            B[i] = {0, 0};
            for (int j = 1; j <= m; j++) {
                time += A[j];
                if (time > h) break;

                B[i].fi++;
                B[i].se += time;
            }
        }

        int better = 0;
        for (int i = 2; i <= n; i++) {
            if (B[i].fi > B[1].fi) better++;
            else if (B[i].fi == B[1].fi && B[i].se < B[1].se) {
                better++;
            } 
        }
        cout << better + 1 << "\n";
    }
    return 0;
}