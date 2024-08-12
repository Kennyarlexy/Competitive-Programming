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
    ll N, B, H, W;
    while (cin >> N >> B >> H >> W) {
        bool OK = false;
        ll Min = LONG_LONG_MAX;
        for (ll h = 1; h <= H; h++) {
            ll p; cin >> p;
            for (ll w = 1; w <= W; w++) {
                ll a; cin >> a;
                if (a >= N && p*N <= B) {
                    Min = min(Min, p*N);
                    OK = true;
                }
            }
        }

        if (OK) cout << Min << "\n";
        else cout << "stay home\n";
    }

    return 0;
}