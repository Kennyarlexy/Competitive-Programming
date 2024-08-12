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
        int n; cin >> n;
        if (n % 2 == 1) {
            cout << "NO\n";
        } else {
            int j = 1;
            cout << "YES\n";
            for (int i = 2; i <= n; i+=2) {
                if (j % 2 == 1) cout << "AA";
                else cout << "BB";
                j++;
            }
            cout << "\n";
        }
    }
    
    return 0;
}