#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string s; cin >> s;

        unordered_map<char, int> cnt;

        for (auto& ch : s) {
            cnt[ch]++;
        }

        for (auto& ch : s) {
            if (ch == '0') {
                if (cnt['1'] != 0) cnt['1']--;
                else break;
            } else {
                if (cnt['0'] != 0) cnt['0']--;
                else break;
            }
        }

        cout << cnt['0'] + cnt['1'] << "\n";
    }
    
    
    return 0;
}