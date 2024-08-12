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
        string s1, s2; cin >> s1 >> s2;
        int n = s1.length(), m = s2.length();

        int j = 0;
        for (int i = 0; i < n && j < m; i++) {
            if (s1[i] == s2[j]) j++;
            else if (s1[i] == '?') {
                s1[i] = s2[j];
                j++;
            }
        }

        if (j == m) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                if (s1[i] == '?') s1[i] = 'a';
            }
            cout << s1 << "\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0; 
}