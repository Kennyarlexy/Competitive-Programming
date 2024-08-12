#include <bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<char, int> cnt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        cnt = {};

        for (auto& ch : s) {
            cnt[ch]++;
        }

        int ganjil = 0;
        for (auto& [ch, count] : cnt) {
            ganjil += (count % 2);
        }

        if (k >= ganjil - 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}

