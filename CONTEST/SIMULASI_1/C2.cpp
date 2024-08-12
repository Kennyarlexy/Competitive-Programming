#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[200005];

int main() {
    fast_io();
    //use ll when possible!
    ll n; cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> A[i];
    }    

    ll res = LONG_LONG_MIN;
    ll cursum = 0;
    bool OK = false;
    for (ll i = 0; i < n; i++) {
        if (A[i] > 0) OK = true;
        cursum = max(A[i], cursum + A[i]);
        res = max(res, cursum);
    }

    if (OK) cout << res << "\n";
    else cout << "0\n";

    return 0;
}