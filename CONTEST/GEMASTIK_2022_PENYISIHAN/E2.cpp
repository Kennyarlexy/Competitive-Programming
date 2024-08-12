#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll cnt[1000005];

int main() {
    fast_io();
    //use ll when possible!
    ll xb, yb; cin >> xb >> yb;

    ll N; cin >> N;
    for (ll i = 1; i <= N; i++) {
        ll xc, yc; cin >> xc >> yc;
        ll d2 = (xc-xb)*(xc-xb) + (yc-yb)*(yc-yb);
        ll d = sqrt(d2);

        if (d <= 1000000) {
            if (d*d == d2) cnt[d]++;
            else cnt[d+1]++;
        }
    }


    for (ll i = 1; i <= 1000000; i++) {
        cnt[i] += cnt[i-1];
    }
    ll Q; cin >> Q;

    for (ll q = 1; q <= Q; q++) {
        ll r; cin >> r;
        cout << cnt[r] << "\n";
    }

    return 0;
}

/*
3 1
7
4 3
-2 -2
3 -2
3 -4
6 1
-3 5
8 5
2
5
1


0 0
4
0 1
0 2
0 3
0 4
6
1 2 3 4 5 6

0 0
4
0 0
0 0
3 4
4 4
5
1 2 3 4 5

0 0
1
1000000 1000000
1
1000000
*/