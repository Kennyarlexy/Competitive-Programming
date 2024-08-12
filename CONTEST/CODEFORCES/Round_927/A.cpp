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
        string s; cin >> s;
        int ans = 0;
        int len = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '@') ans++;
            if (s[i] == '*') len++;
            else len = 0;
            if (len >= 2) break;
        }
        cout << ans << "\n";
    }
    
    return 0;
}