#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

pair<ll, ll> A[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll n, m; cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> A[i].fi;
        for (int i = 1; i <= n; i++) cin >> A[i].se;

        sort(A+1, A+1+n);

        ll mx = 0;
        for (int i = 1; i <= n && m >= A[i].fi; i++) {
            ll _m = m;
            ll k = min(A[i].se, _m/A[i].fi);
            ll X = k*A[i].fi;
            _m -= X;
            if (i < n && A[i+1].fi - A[i].fi == 1 ) {
                ll k2 = min(A[i+1].se, _m/A[i+1].fi);
                ll X2 = k2*A[i+1].fi;
                X += X2;
                _m -= X2;

                // assert(min(_m, min(A[i+1].se - k2, A[i].se - 1)) >= 0);
                X += min(_m, min(k, min(A[i+1].se - k2, A[i].se - 1)));
            }

            mx = max(mx, X);
        }

        cout << mx << "\n";
    }
    
    return 0;
}

/*
1
6 20
1 2 4 5 6 7
7 2 1 3 1 1

1
5 10
1 2 3 4 5
1 1 1 1 2

1
5 11
2 3 4 5 6
1 1 1 1 1

1
2 303
100 101
2 2

1
5 100
9 12 14 16 18
10 1000 1000 1000 1000



1
5 10
11 12 13 14 15
100 100 1001 100 100

1
2 20
10 11
100 100


1
2 8
1 9
6 2

1
2 15
10 11
5 4
*/