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
        ll streak = 0;
        ll score = 0;
        for (ll i = 0; i < s.length(); i++) {
            if (s[i] == 'O') streak++;
            else streak = 0;
            score += streak;
        }
        cout << score << "\n";
    }

    return 0;
}