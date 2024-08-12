#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    ll mod = 1e9 + 7;
    for (ll t = 1; t <= T; t++) {
        string s; cin >> s;
        ll res = 0;
        ll m = (s.length()-1)/2, l, r;
        if (s.length() % 2 == 1) {
            if (s[m] == '1') res = 1;
            l = m-1, r = m+1;
        } else {
            l = m, r = m+1;
        }

        while (l >= 0) {
            if (s[l] >= s[r]) {
                res = (res << 1) | (s[l] == '1');
                res = (res << 1) | (s[r] == '1');
            } else {
                res = (res << 1) | (s[r] == '1');
                res = (res << 1) | (s[l] == '1');
            }
            l--, r++;
            res = res % mod;
        }
        
        cout << "Case #" << t << ": " << res << "\n";
    }
    
    return 0;
}