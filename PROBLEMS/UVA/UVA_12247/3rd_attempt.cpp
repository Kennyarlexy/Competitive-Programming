#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll c[5];
bool used[100];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> c[0] >> c[1] >> c[2] >> c[3] >> c[4] && c[0]) {
        memset(used, 0, sizeof(used));
        if (c[3] > c[4]) swap(c[3], c[4]);
        set<ll> S;
        for (ll i = 0; i < 3; i++) {
            S.insert(c[i]);
        }
        for (ll i = 0; i < 5; i++) {
            used[c[i]] = true;
        }

        for (ll i = 3; i < 5; i++) {
            auto it = S.lower_bound(c[i]);
            if (it != S.end()) {
                S.erase(*it);
            }
        }

        if (S.size() <= 1) {
            cout << "-1\n";
        } else {
            auto it = S.end(); it--;
            bool OK = false;
            for (ll i = (S.size() == 2 ? *it + 1 : 1); i <= 52; i++) {
                if (!used[i]) {
                    cout << i << "\n";
                    OK = true;
                    break;
                }
            }
            if (!OK) cout << "-1\n";
        }
    }
    
    return 0;
}