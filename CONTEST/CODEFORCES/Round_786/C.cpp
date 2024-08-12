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
        string a, b; cin >> a >> b;
        int count = 0, hasA = false;
        for (auto& ch : b) {
            if (ch == 'a') {
                hasA = true;
                break;
            }
        }

        if (hasA) {
            if (b.length() > 1) {
                cout << "-1\n";
            } else {
                cout << "1\n";
            }
        } else {
            ll result = pow(2, a.length());
            cout << result << "\n";
        }
    }

    return 0;
}