//time complexity of O(N^3*log(N))
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

map<ll, ll> possible;
ll X[105];

int main() {
    fast_io();
    //use ll when possible!
    ll N; cin >> N;
    for (ll i = 1; i <= N; i++) {
        cin >> X[i];
    }

    for (ll id = 1; id <= N; id++) 
    for (ll ie = 1; ie <= N; ie++) 
    for (ll iF = 1; iF <= N; iF++) {
        if (X[id] == 0) continue;
        possible[X[id]*(X[ie] + X[iF])]++;
    }

    ll res = 0;
    for (ll ia = 1; ia <= N; ia++)
    for (ll ib = 1; ib <= N; ib++)
    for (ll ic = 1; ic <= N; ic++) {
        ll check = X[ia]*X[ib] + X[ic];
        res += possible[check];
    }

    cout << res << "\n";
    
    return 0;
}