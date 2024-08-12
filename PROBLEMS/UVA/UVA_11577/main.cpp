#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll cnt[300];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    cin.ignore(1000, '\n');
    for (ll t = 1; t <= T; t++) {
        memset(cnt, 0, sizeof(cnt));
        string line;
        getline(cin, line);
        for (auto& ch : line) {
            ch = tolower(ch);
            cnt[ch]++;
        }

        ll _max = LONG_LONG_MIN;
        for (ll i = 'a'; i <= 'z'; i++) {
            _max = max(_max, cnt[i]);
        }

        for (ll i = 'a'; i <= 'z'; i++) {
            if (cnt[i] == _max) cout << (char) i;
        }
        cout << "\n";
    }
    
    return 0;
}

/*
2
Computers account for only 5% of the country's commercial electricity consumption.
Computers account for only 5% of the country's commercial electricity consumption.
*/