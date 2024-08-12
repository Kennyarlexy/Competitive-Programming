#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll cnt[300];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string line;
    while (getline(cin, line)) {
        memset(cnt, 0, sizeof(cnt));
        for (auto& ch : line) {
            cnt[ch]++;
        }

        ll _max = LONG_LONG_MIN;
        for (ll i = 0; i <= 255; i++) {
            if (!isalpha(i)) continue;
            _max = max(_max, cnt[i]);
        }

        for (ll i = 0; i <= 255; i++) {
            if (!isalpha(i)) continue;
            if (cnt[i] == _max) cout << (char) i;
        }
        cout << " " << _max << "\n";
    }
    
    return 0;
}