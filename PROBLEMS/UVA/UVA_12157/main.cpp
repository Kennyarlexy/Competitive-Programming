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
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll N; cin >> N;
        ll mile = 0, juice = 0;
        for (ll i = 1; i <= N; i++) {
            ll a; cin >> a;
            mile += (a/30 + 1) * 10;
            juice += (a/60 + 1) * 15;
        }

        cout << "Case " << t << ": ";
        if (mile < juice) cout << "Mile " << mile << "\n";
        else if (mile > juice) cout << "Juice " << juice << "\n";
        else cout << "Mile Juice " << mile << "\n";
    }

    return 0;
}