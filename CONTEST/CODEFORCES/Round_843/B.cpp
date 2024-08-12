#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

bool F[200005];
bool B[200005];
vector<ll> A[100005];

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll n; cin >> n;
        
        for (ll i = 1; i <= n; i++) {
            ll k; cin >> k;
            A[i] = {};
            for (ll j = 1; j <= k; j++) {
                ll index; cin >> index;
                A[i].push_back(index);
                F[index] = false;
                B[index] = false;
            }
        }

        bool OKF = false;
        for (ll i = 1; i <= n; i++) {
            bool changedF = false;
            for (ll j = 0; j < A[i].size(); j++) {
                if (!F[A[i][j]]) changedF = true;
                F[A[i][j]] = true;
            }
            if (!changedF) {
                OKF = true;
                break;
            }
        }

        if (OKF) {
            cout << "YES\n";
            continue;
        }

        bool OKB = false;
        for (ll i = n; i >= 1; i--) {
            bool changedB = false;
            for (ll j = 0; j < A[i].size(); j++) {
                if (!B[A[i][j]]) changedB = true;
                B[A[i][j]] = true;
            }
            if (!changedB) {
                OKB = true;
                break;
            }
        }

        if (OKB) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

/*
1
3
1 3
2 3 2
3 3 2 1
*/