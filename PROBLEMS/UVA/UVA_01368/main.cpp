#include <bits/stdc++.h>
#define ll long long
using namespace std;

char A[] = {'A', 'C', 'G', 'T'};
unordered_map<char, ll> MP[1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll m, n; cin >> m >> n;
        for (ll i = 0; i < n; i++) {
            MP[i] = {};
        }
        
        for (ll i = 1; i <= m; i++) {
            string DNA; cin >> DNA;
            for (ll j = 0; j < n; j++) {
                MP[j][DNA[j]]++;
            }
        }

        string res;
        ll dist = 0;
        for (ll i = 0; i < n; i++) {
            char ch;
            ll _max = LONG_LONG_MIN;
            for (ll j = 3; j >= 0; j--) {
                if (MP[i][A[j]] >= _max) {
                    _max = MP[i][A[j]];
                    ch = A[j];
                }
            }

            res += ch;
            dist += m - _max;
        }
        cout << res << "\n" << dist << "\n";
    }
    
    return 0;
}