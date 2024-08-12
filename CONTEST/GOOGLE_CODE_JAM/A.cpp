#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int R, C; cin >> R >> C;
        cout << "Case #" << t << ":\n";
        //total R = 2R + 1, C = 2C + 1
        for (int r = 1; r <= 2*R + 1; r++) {
            for (int c = 1; c <= 2*C + 1; c++) {
                if (r <= 2 && c <= 2) {
                    cout << ".";
                } else if (r % 2 == 1) {
                    cout << (c % 2 == 0 ? "-" : "+");
                } else {
                    cout << (c % 2 == 0 ? "." : "|");
                }
            }
            cout << "\n";
        }
    }

    return 0;
}