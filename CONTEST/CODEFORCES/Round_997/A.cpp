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
        int n, m; cin >> n >> m;

        int _x, _y;
        int x_max = 0, y_max = 0;
        for (int i = 1; i <= n; i++) {
            int x, y; cin >> x >> y;
            if (i == 1) {
                _x = x;
                _y = y;
            }

            x_max += x;
            y_max += y;
        }

        int ans = 2*(x_max+m-1 - (_x - 1) + y_max+m-1 - (_y - 1));
        cout << ans << "\n";
    }
    
    return 0;
}