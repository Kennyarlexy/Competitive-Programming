#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

map<ll, ll> MP;

int main() {
    fast_io();
    //use ll when possible!
    ll xb, yb; cin >> xb >> yb;

    ll N; cin >> N;
    for (ll i = 1; i <= N; i++) {
        ll xc, yc; cin >> xc >> yc;
        ll d = (xc-xb)*(xc-xb) + (yc-yb)*(yc-yb);
        MP[d]++;
    }

    ll Q; cin >> Q;
    ll total = 0;
    for (auto& data : MP) {
        data.second += total;
        total = data.second;
    }

    for (ll q = 1; q <= Q; q++) {
        ll r; cin >> r;
        cout << MP[r*r] << "\n";
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
*/