#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

pair<ll, ll> A[10005];
ll k = 1e12;

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.se == b.se) {
        if ((a.fi+k)%2 != (b.fi+k)%2) {
            return (a.fi+k)%2 == 1;
        } else if ((a.fi+k)%2 == 1 && (b.fi+k)%2 == 1) {
            return a.fi > b.fi;
        } else {
            return a.fi < b.fi;
        }
    }
    return a.se < b.se;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, M;
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        for (ll i = 1; i <= N; i++) {
            ll a; cin >> a;
            A[i] = {a, a % M};
        }

        sort(A+1, A+N+1, cmp);
        cout << N << " " << M << "\n";
        for (ll i = 1; i <= N; i++) {
            cout << A[i].fi << "\n";
        }
    }
    cout << "0 0\n";
    
    return 0;
}