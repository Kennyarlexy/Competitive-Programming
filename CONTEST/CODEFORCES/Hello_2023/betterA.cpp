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
        ll n; cin >> n;
        string s; cin >> s;

        bool OK = false;
        ll iS = -1;
        for (ll i = 0; i < n-1; i++) {
            if (s[i] == 'R' && s[i+1] == 'L') {
                OK = true;
            } else if (s[i] == 'L' && s[i+1] == 'R') {
                iS = i+1;
            }
        }

        if (OK) cout << "0\n";
        else if (iS != -1) cout << iS << "\n";
        else cout << "-1\n";
    }

    return 0;
}