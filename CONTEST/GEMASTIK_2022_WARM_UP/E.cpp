#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[1000005];

int main() {
    fast_io();
    //use ll when possible!
    ll N; cin >> N;
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll buy = 0;
    ll res = 0;
    for (ll i = 0; i < N; i++) {
        if (A[i] < A[i+1] && buy == 0) {
            buy = A[i];
            // cout << "buy = " << buy << "\n";
        } else if (A[i] > A[i+1] && buy != 0) {
            res += (A[i] - buy);
            // cout << "sell = " << A[i]-buy << "\n";
            buy = 0;
        }
    }

    cout << res << "\n";

    return 0;
}