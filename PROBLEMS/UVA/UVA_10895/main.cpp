#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

vector<pair<ll, ll>> A[10005];
ll B[10005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll m, n;
    while (cin >> m >> n) {
        memset(A, 0, sizeof(vector<pair<ll, ll>>) * (n + 5));
        for (ll r = 1; r <= m; r++) {
            ll k; cin >> k;
            for (ll i = 1; i <= k; i++) {
                cin >> B[i];
            }

            for (ll i = 1; i <= k; i++) {
                ll a; cin >> a;
                A[B[i]].push_back({a, r});
            }
        }

        cout << n << " " << m << "\n";
        for (ll r = 1; r <= n; r++) {
            ll size = A[r].size();
            cout << size;
            for (ll i = 0; i < size; i++) {
                cout << " " << A[r][i].se;
            }
            cout << "\n";

            if (size != 0) cout << A[r][0].fi;
            for (ll i = 1; i < size; i++) {
                cout << " " << A[r][i].fi;
            }
            cout << "\n";
        }
    }
    
    return 0;
}
/*
4 3
3 1 2 3
1 3 2
2 2 3
4 -1
0

3 1 2 3
5 -2 11
*/