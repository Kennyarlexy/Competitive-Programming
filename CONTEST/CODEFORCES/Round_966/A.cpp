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
        string s; cin >> s;
        int m = s.size();
        if (m <= 2) {
            cout << "NO\n";
        } else {
            if (s.substr(0, 2) != "10" || s[2] == '0' || s == "101") cout << "NO\n";
            else cout << "YES\n";
        }
    }
    
    return 0;
}