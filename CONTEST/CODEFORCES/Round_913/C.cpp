#include <bits/stdc++.h>
#define ll long long

using namespace std;

unordered_map<char, int> cnt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cnt = {};
        int n; cin >> n;
        string s; cin >> s;
        for (int i = 0; i < n; i++) {
            cnt[s[i]]++;
        }

        int _max = 0;
        for (auto& [ch, count] : cnt) {
            _max = max(_max, count);
        }

        int ans = _max > n/2 ? _max - (n-_max) : n % 2;

        cout << ans << "\n";
    }
    
    return 0;
}