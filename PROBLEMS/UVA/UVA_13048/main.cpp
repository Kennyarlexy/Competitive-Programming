#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool bad[55];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        string s; cin >> s;
        memset(bad, 0, sizeof(bad));

        for (ll i = 0; s[i]; i++) {
            if (s[i] == 'D') bad[i] = true;
            else if (s[i] == 'B') {
                bad[i] = true;
                if (i-1 >= 0) bad[i-1] = true;
                if (i-2 >= 0) bad[i-2] = true;
            }
            else if (s[i] == 'S') {
                bad[i] = true;
                if (i+1 < s.length()) bad[i+1] = true;
                if (i-1 >= 0) bad[i-1] = true;
            }
        }

        ll cnt = 0;
        for (ll i = 0; i < s.length(); i++) {
            if (!bad[i]) cnt++;
        }

        cout << "Case " << t << ": " << cnt << "\n";
    }
    
    return 0;
}