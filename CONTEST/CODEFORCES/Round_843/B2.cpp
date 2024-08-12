#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

vector<ll> A[100005];
ll cnt[200005];

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll n; cin >> n;
        for (ll i = 1; i <= n; i++) {
            ll k; cin >> k;
            A[i].resize(k);
            for (auto& index : A[i]) {
                cin >> index;
                cnt[index] = 0;
            }
        }

        for (ll i = 1; i <= n; i++) {
            for (auto& index : A[i]) {
                cnt[index]++;
            }
        }

        bool OK;
        for (ll i = 1; i <= n; i++) {
            OK = true;
            for (auto& index : A[i]) {
                if (cnt[index] < 2) OK = false;
            }
            if (OK) break;
        }

        if (OK) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}