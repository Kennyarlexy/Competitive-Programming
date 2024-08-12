#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

pair<ll, ll> A[200005];

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll n, k; cin >> n >> k;
        for (ll i = 0; i < n; i++) {
            cin >> A[i].first;
        }

        for (ll i = 0; i < n; i++) {
            cin >> A[i].second;
        }

        sort(A, A + n);
        
        for (ll i = n-2; i >= 0; i--) {
            A[i].second = min(A[i].second, A[i+1].second);
        }

        ll total_dmg = 0;
        ll i = 0;
        while (k > 0 && i < n) {
            total_dmg += k;
            while (i < n && A[i].first <= total_dmg) i++;
            k -= A[i].second;
        }

        if (i == n) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}