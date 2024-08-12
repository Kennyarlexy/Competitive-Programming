#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string s; cin >> s;
        stack<int> up, low;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'B') {
                s[i] = '.';
                if (!up.empty()) {
                    int j = up.top(); up.pop();
                    s[j] = '.';
                }
            } else if (s[i] == 'b') {
                s[i] = '.';
                if (!low.empty()) {
                    int j = low.top(); low.pop();
                    s[j] = '.';
                }
            }
            else if (isupper(s[i])) up.push(i);
            else low.push(i);
        }

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '.') cout << s[i];
        }
        cout << "\n";
    }
    
    return 0;
}