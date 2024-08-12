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
        int len; cin >> len;
        string s; cin >> s;
        int count = 0;
        for (int i = 0; i < len - 1; i+=2) {
            if (s[i] != s[i+1]) count++;
        }
        cout << count << "\n";
    }

    return 0;
}