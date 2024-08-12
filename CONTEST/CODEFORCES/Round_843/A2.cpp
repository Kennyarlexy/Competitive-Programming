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
        if (s[1] == 'a') cout << s[0] << " " << s[1] << " " << s.substr(2) << "\n";
        else cout << s[0] << " " << s.substr(1, s.length()-2) << " " << s.back() << "\n";
    }

    return 0;
}