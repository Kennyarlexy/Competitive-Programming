#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string s1, s2; cin >> s1 >> s2;
        int same = 0;
        if (s1 == s2) {
            cout << "Case #" << t << ": 0\n";
            continue;
        } else if (s2.length() >= s1.length()) {
            int idx_s1 = 0;
            for (auto& ch : s2) {
                if(idx_s1 == s1.length()) break;
                if (ch == s1[idx_s1]) {
                    same++;
                } else {
                    continue;
                }
                idx_s1++;
            }
        }
        int result = s2.length() - same;
        if (same >= s1.length()) {
            cout << "Case #" << t << ": " << result << "\n";
        } else {
            cout << "Case #" << t << ": IMPOSSIBLE\n";
        }
    }

    return 0;
}