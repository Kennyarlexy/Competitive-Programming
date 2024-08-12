#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

char f(char ch) {
    if (ch == 'z') return 'a';
    return ch + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string s; cin >> s;
        int n = s.size();
     
        bool OK = false;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i-1]) {
                s.insert(i, 1, f(s[i]));
                OK = true;
                break;
            }
        }

        if (!OK) s.push_back(f(s.back()));
        cout << s << "\n";
    }
    
    return 0;
}