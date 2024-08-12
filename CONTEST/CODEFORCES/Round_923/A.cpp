#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define LSOne(x) ((x) & (-x))
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        string s; cin >> s;
        int l = -1, r = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'B') {
                if (l == -1) l = i;
                r = i;
            }
        }

        int ans = r-l+1;
        cout << ans << "\n";
    }
    
    return 0;
}