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
    ll H, L;
    while (true) {
        cin >> H;
        if (H == 0) break;
        cin >> L;

        ll res = 0;
        for (ll i = 1; i <= L; i++) {
            ll h; cin >> h;
            if (h < H) res += H-h;
            H = h;
        }
        cout << res << "\n";
    }    

    return 0;
}