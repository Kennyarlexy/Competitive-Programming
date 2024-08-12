#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

pair<ll, ll> A[1005];
set<ll> unique;

int main() {
    fast_io();
    //use ll when possible!
    ll N; cin >> N;
    for (ll i = 1; i <= N; i++) {
        cin >> A[i].fi;
        A[i].se = i;
    }

    sort(A+1, A+N+1);
    bool flag = true;
    for (ll i = 2; i <= N; i++) {
        if (A[i].fi != A[i-1].fi) {
            flag = false;
            break;
        }
    }

    if (flag) cout << "SESUAI\n";
    else {
        ll X = A[N].fi - A[1].fi;
        if (X % 2 != 0) {
            cout << "TIDAK SESUAI\n";
        } else if (N == 2) {
            cout << X/2 << " " << A[N].se << " " << A[1].se << "\n";
        } else {
            if (A[N].fi + A[1].fi != 2*A[2].fi) cout << "TIDAK SESUAI\n";
            else {
                cout << X/2 << " " << A[N].se << " " << A[1].se << "\n";
            }
        }
    }

    return 0;
}

/*
3
270
250
230
*/