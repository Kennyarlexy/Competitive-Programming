#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[101005];

int main() {
    fast_io();
    //use ll when possible!
    ll n, k; cin >> n >> k;
    for (ll i = 1; i <= n; i++) {
        ll t; cin >> t;
        A[t]++;
        A[t+1000]--;
    }

    ll max_request = 0;
    ll cur = 0;
    for (ll i = 0; i <= 100000; i++) {
        cur += A[i];
        max_request = max(max_request, cur);
    }


    ll res = max(1LL, (max_request + (k - 1)) / k);
    // ll res = 1 + (max_request - 1) / k; //same with above
    cout << res << "\n";

    return 0;
}