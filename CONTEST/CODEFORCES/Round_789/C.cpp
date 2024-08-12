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
        int segment = 0;
        char prev = '?';
        bool OK = false;
        for (int i = 0; i < len-1; i+=2) {
            if (s[i] != s[i+1]) continue;

            OK = true;
            if (s[i] != prev && prev != '?') {
                segment++;
            }
            for (int toleft = i-2; toleft >= 0; toleft-=2) {
                if (s[toleft] == s[toleft+1]) break;
                s[toleft] = s[i];
                s[toleft+1] = s[i];
                count++;
            }
            for (int toright = i+2; toright < len-1; toright+=2) {
                if (s[toright] == s[toright+1]) break;
                s[toright] = s[i];
                s[toright+1] = s[i];
                count++;
            }
            prev = s[i];
        }

        if (!OK) {
            for (int i = 0; i < len - 1; i+=2) {
                if (s[i] != s[i+1]) count++;
            }
        }
        cout << count << " " << segment + 1 << "\n";
    }

    return 0;
}