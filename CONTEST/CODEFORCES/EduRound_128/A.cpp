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
    for (int t = 0; t < T; t++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (r1 < l2 || r2 < l1) {
            int result = l1 + l2;
            cout << result << "\n";
        } else {
            int pos[] = {l1, r1, l2, r2};
            sort(pos, pos + 4);
            cout << pos[1] << "\n";
        }
    }

    return 0;
}