#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[100005];
ll min_in_range[20][100005]; //the row in this table denotes the exponent of 2, which is the width

ll minq(ll L, ll R) {
    if (L == R) return min_in_range[0][L] = A[L];

    ll W = R - L + 1;
    ll hW = W / 2; //half width
    ll exp = 63 - __builtin_clzll(W); //log2(W)
    if (min_in_range[exp][L] != -1) return min_in_range[exp][L];

    return min_in_range[exp][L] = min(minq(L, L+hW-1), minq(L+hW, R));
}

int main() {
    fast_io();
    memset(min_in_range, -1, sizeof(min_in_range));
    //use ll when possible!
    ll N; cin >> N;
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll exp = 63 - __builtin_clzll(N); //exp where 2^exp <= N, log2(N), the row of the table. this is the derived form, the original form is exp = 64 - __builtin_clzll(N) - 1. think about the count first instead of index
    ll W = (1LL << exp);
    for (ll i = 0; i < N; i++) {
        //since this width is not possible, we reduce the width by half, continue the process to fill the table
        if (i+W-1 >= N) W /= 2;
        //once entering this function, fill the table for all exp that starts from index i;
        minq(i, i+W-1);
    }
    

    ll Q; cin >> Q;
    for (ll q = 1; q <= Q; q++) {
        ll L, R; cin >> L >> R;
        ll W = R - L + 1;
        ll exp = 63 - __builtin_clzll(W);
        ll res = min(min_in_range[exp][L], min_in_range[exp][R-(1LL << exp)+1]);
        cout << res << "\n";
    }

    return 0;

}