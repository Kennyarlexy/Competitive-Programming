#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[1005];

int main() {
    fast_io();
    //use ll when possible!
    ll N; cin >> N;
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }    

    ll res = LONG_LONG_MIN;
    ll cur = 0;
    for (ll i = 0; i < N; i++) {
        cur = max(cur + A[i], A[i]);
        res = max(res, cur);
    }

    cout << res << "\n";

    return 0;
}