#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[200005];
ll X[105];

int main() {
    fast_io();
    //use ll when possible!
    ll* possible = &A[100000]; //biar bisa negative index
    ll N; cin >> N;
    for (ll i = 1; i <= N; i++) {
        cin >> X[i];
    }

    //bruteforce semua hasil dari e + f, harusnya ga akan mungkin lebih kecil dri -60000 atau lebih besar dri 60000
    for (ll ie = 1; ie <= N; ie++) {
        for (ll iF = 1; iF <= N; iF++) {
            possible[X[ie] + X[iF]] += 1;
        }
    }

    ll res = 0;
    //bruteforce semua hasil dari (a*b + c) / d
    for (ll ia = 1; ia <= N; ia++)
    for (ll ib = 1; ib <= N; ib++)
    for (ll ic = 1; ic <= N; ic++)
    for (ll id = 1; id <= N; id++) {
        if (X[id] == 0) continue;
        ll top = (X[ia]*X[ib]) + X[ic];
        if (top % X[id] != 0) continue;

        ll check = top / X[id];
        if (check >= -60000 && check <= 60000) res += possible[check];
    }

    cout << res << "\n";
    // cout << possible[-100000] << "\n";
    // cout << possible[100000] << "\n";
    // cout << "no error\n";
    
    return 0;
}