//this solution works fine even for large t
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    //use ll when possible!
    ll n, k; cin >> n >> k;
    queue<ll> Q;
    ll max_request = 0;
    for (ll i = 1; i <= n; i++) {
        ll t; cin >> t;
        while (!Q.empty() && Q.front()+1000 <= t) Q.pop();
        Q.push(t);
        max_request = max(max_request, (ll) Q.size());
    }

    ll res = max(1LL, (max_request + k - 1) / k);
    cout << res << "\n";

    return 0;
}