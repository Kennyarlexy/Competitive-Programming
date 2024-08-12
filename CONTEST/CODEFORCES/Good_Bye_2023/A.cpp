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
        int n, k; cin >> n >> k;

        int X = 1;
        for (int i = 1; i <= n; i++) {
            int b; cin >> b;
            X *= b;
        }

        if (2023 % X == 0) {
            cout << "YES\n";
            cout << 2023 / X;
            for (int i = 2; i <= k; i++) {
                cout << " 1";
            }
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}