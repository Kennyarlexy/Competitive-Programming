#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll D[300005];

int main() {
    fast_io();
    //use ll when possible!
    ll N, M; cin >> M;
    for (ll i = 1; i <= M; i++) {
        cin >> D[i];
    }

    ll pos_diameter = LONG_LONG_MIN;
    ll A, B;
    for (ll i = 1; i <= N; i++) {
        pos_diameter = max(pos_diameter, D[i]);
        A = i;
        B = i+1;
    }

    

    return 0;
}