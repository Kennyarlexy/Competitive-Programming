#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second 
using namespace std;

char last[30];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, k, m; cin >> n >> k >> m;

        string s; cin >> s;
        int BS = (1 << k) - 1;
        int cnt = 0;
        for (int i = 0; i < m && cnt < n; i++) {
            BS &= ~(1 << (s[i] - 'a'));
            if (BS == 0) {
                cnt++;
                BS = (1 << k) - 1;
                last[cnt] = s[i];
            }
        }

        if (cnt == n) cout << "YES\n";
        else {
            cout << "NO\n";
            for (int i = 1; i <= cnt; i++) {
                cout << last[i];
            }

            for (int i = 0; i < k; i++) {
                if (BS & (1 << i)) {
                    char ch = i + 'a';
                    cout << ch;
                    break;
                }
            }

            for (int i = cnt+2; i <= n; i++) cout << 'a';
            cout << "\n";
        }
    }
    
    return 0;
}