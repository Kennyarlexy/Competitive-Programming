#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        int m = (n % 2 == 0) ? n-1 : n;
        for (int i = 1; i <= m; i++) {
            if (i % 2 == 1) {
                cout << "-1 ";
            } else {
                cout << "3 ";
            }
        }
        if (n % 2 == 0) {
            cout << "2\n";
        } else {
            cout << "\n";
        }
    }
    
    return 0;
}