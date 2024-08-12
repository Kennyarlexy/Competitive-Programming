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
        string s; cin >> s;
        ll i = 0;
        double mass = 0;
        while (i < s.length()) {
            char atom = s[i];
            bool hasIndex = false;
            ll n = 0;
            i++;
            while (i < s.length() && s[i] >= '1' && s[i] <= '9') {
                hasIndex = true;
                n = n*10 + s[i] - '0';
                i++;
            }
            
            if (!hasIndex) n = 1;
            if (atom == 'C') mass += n*12.01;
            else if (atom == 'H') mass += n*1.008;
            else if (atom == 'O') mass += n*16;
            else mass += n*14.01;
        }
        cout << fixed << setprecision(3) << mass << "\n";
    }

    return 0;
}