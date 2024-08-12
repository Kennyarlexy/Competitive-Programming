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
    ll N;
    ll t = 0;
    while (true) {
        cin >> N;
        if (N == 0) break;
        ll cnt_0 = 0;
        for (ll i = 1; i <= N; i++) {
            ll a; cin >> a;
            if (a == 0) cnt_0++;
        }

        ll res = N - 2*cnt_0;
        cout << "Case " << ++t << ": " << res << "\n";
    }

    return 0;
}