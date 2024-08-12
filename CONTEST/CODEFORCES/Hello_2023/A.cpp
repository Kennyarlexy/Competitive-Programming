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
        string s; cin >> s;

        ll iR = -1;
        for (ll i = 0; i < N; i++) {
            if (s[i] == 'R') {
                iR = i;
                break;
            }
        }

        ll iL = -1;
        for (ll i = N-1; i >= 0; i--) {
            if (s[i] == 'L') {
                iL = i;
                break;
            }
        }

        bool OK = false;
        ll iS = -1;
        for (ll i = 0; i < N-1; i++) {
            if (s[i] == 'L' && s[i+1] == 'R') {
                OK = true;
                iS = i;
                break;
            }
        }

        if (iR == -1 || iL == -1) cout << "-1\n";
        else if (iL > iR) cout << "0\n";
        else if (OK) cout << iS+1 << "\n";
        else cout << "-1\n";
    }

    return 0;
}