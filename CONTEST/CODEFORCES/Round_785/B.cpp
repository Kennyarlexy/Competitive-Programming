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
    for (int t = 1; t <= T; t++) {
        string s; cin >> s;
        set<char> ch;
        for (int i = 0; i < s.length(); i++) {
            if (ch.find(s[i]) != ch.end() && i != 0) break;
            ch.insert(s[i]);
        }
        int step = ch.size();
        bool OK = true;
        for (int i = 0; i < s.length() - step; i++) {
            if (s[i] != s[i+step]) {
                OK = false;
                break;
            }
        }
        if (OK) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}