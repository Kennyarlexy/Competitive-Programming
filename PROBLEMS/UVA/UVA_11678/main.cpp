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
    ll A, B;
    while (cin >> A >> B && (A || B)) {
        set<ll> X, Y;
        for (ll i = 1; i <= A; i++) {
            ll x; cin >> x;
            X.insert(x);
        }
        for (ll i = 1; i <= B; i++) {
            ll y; cin >> y;
            Y.insert(y);
        }

        ll cnt_X = 0;
        for (auto& card : X) {
            if (Y.find(card) == Y.end()) cnt_X++;
        }

        ll cnt_Y = 0;
        for (auto& card : Y) {
            if (X.find(card) == X.end()) cnt_Y++;
        }
        cout << min(cnt_X, cnt_Y) << "\n";
    }

    return 0;
}