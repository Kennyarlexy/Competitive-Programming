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
        int n, m; cin >> n >> m;
        int firstR = -1;
        int otherR = INT_MAX;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                char ch; cin >> ch;
                if (ch == 'R') {
                    if (firstR == -1) firstR = c;
                    otherR = min(otherR, c);
                }
            }
        }
        if (otherR < firstR) cout << "NO\n";
        else cout << "YES\n";
    
    }

    return 0;
}