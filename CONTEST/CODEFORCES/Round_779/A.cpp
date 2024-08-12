#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t; cin >> t;
    for (int T = 1; T <= t; T++) {
        int n; cin >> n;
        string s; cin >> s;
        int count = 0;
        if (n == 1 && s == "0") {
            cout << "1\n";
            continue;
        }
        for (int i = 0; i < n-1; i++) {
            if (s[i] == '0' && s[i+1] == '0') count += 2;
        }
        for (int i = 0; i < n-2; i++) {
            if (s[i] == '0' && s[i+1] == '1' && s[i+2] == '0') count += 1;
        }
        cout << count << "\n";
    }

    return 0;
}