#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; getline(cin, s);
    int n = s.length();

    set<char> S;
    vector<char> V(n, false);

    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') continue;
        if (!isalpha(s[i]) && !isdigit(s[i])) {
            V[i] = true;
            if (i > 0) S.insert(s[i-1]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (S.count(s[i])) V[i] = true;
    }

    for (int i = 0; i < n; i++) {
        if (V[i]) continue;
        cout << s[i];
    }
    cout << "\n";
    
    return 0;
}