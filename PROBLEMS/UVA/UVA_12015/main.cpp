#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

string URL[15];
ll V[15];

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll Max = LONG_LONG_MIN;
        for (ll i = 1; i <= 10; i++) {
            cin >> URL[i] >> V[i];            
            Max = max(Max, V[i]);
        }

        cout << "Case #" << t << ":\n";
        for (ll i = 1; i <= 10; i++) {
            if (V[i] == Max) cout << URL[i] << "\n";
        }
    }

    return 0;
}