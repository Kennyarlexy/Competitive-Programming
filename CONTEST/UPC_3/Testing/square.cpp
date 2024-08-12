#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

pair<int, int> P[5];

int dot(pair<int, int> A, pair<int, int> B, pair<int, int> C) {
    pair<int, int> u = {B.fi - A.fi, B.se - A.se};
    pair<int, int> v = {C.fi - A.fi, C.se - A.se};
    return u.fi * v.fi + u.se*v.se;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i <= 3; i++) {
        cin >> P[i].fi >> P[i].se;
    }

    sort(P + 1, P + 4);

    bool OK = false;
    do {
        if (dot(P[1], P[2], P[3]) == 0) {
            OK = true;
            break;
        }
    } while (next_permutation(P+1, P+4));

    if (!OK) cout << "-1\n";
    else {
        P[4] = {P[2].fi + (P[3].fi - P[1].fi), P[2].se + (P[3].se - P[1].se)};

        int dx_1 = P[1].fi - P[4].fi;
        int dy_1 = P[1].se - P[4].se;

        int dx_2 = P[2].fi - P[3].fi;
        int dy_2 = P[2].se - P[3].se;

        if (dx_1*dx_1 + dy_1*dy_1 == dx_2*dx_2 + dy_2*dy_2 && dx_1*dx_2 + dy_1*dy_2 == 0) {
            cout << P[4].fi << " " << P[4].se << "\n";
        } else {
            cout << "-1\n";
        }
    }
    
    return 0;
}

/*
0 -1
1 0
0 1


*/