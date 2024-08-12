#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string s; cin >> s;
        int len = s.length();
        int total = 0;
        for (auto& ch : s) {
            total += (ch - 'a') + 1;
        }
        int A = 0, B = 0;
        if (len % 2 == 0) {
            A = total;
        } else {
            if (len > 2) {
                B = fmin(s[0]-'a' + 1, s.back() - 'a' + 1);
                A = total - B;
            } else {
                B = total;
            }
        }

        if (A > B) {
            cout << "Alice ";
        } else {
            cout << "Bob ";
        }
        cout << abs(A - B) << "\n";
    }

    return 0;
}