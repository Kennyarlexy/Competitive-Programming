#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<char, ll> val = {
    {'B', 1},
    {'U', 10},
    {'S', 100},
    {'P', 1000},
    {'F', 10000},
    {'T', 100000},
    {'M', 1000000}
};

char A[] = {'B', 'U', 'S', 'P', 'F', 'T', 'M'};
ll cnt[300];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        string s; cin >> s;
        memset(cnt, 0, sizeof(cnt));
        if (val[s.front()] < val[s.back()])
            reverse(s.begin(), s.end());

        bool OK = true;
        ll res = 0;
        for (ll i = 0; i < s.length(); i++) {
            if (i > 0 && val[s[i]] > val[s[i-1]]) {
                OK = false;
                break;
            }
            res += val[s[i]];
            cnt[s[i]]++;
        }

        for (ll i = 0; i < 7; i++) {
            if (cnt[A[i]] > 9) {
                OK = false;
                break;
            }
        }
        
        if (OK) cout << res << "\n";
        else cout << "error\n";
    }
    
    return 0;
}