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
    for (int t = 0; t < T; t++) {
        int len; cin >> len;
        string s; cin >> s;
        int mid = ((len+1) / 2) - 1;
        char cmid = s[mid];
        int result = 1;
        for (int i = mid+1; i < len; i++) {
            if (s[i] != cmid) break;
            result++;
        }
        
        for (int i = mid-1; i >= 0; i--) {
            if (s[i] != cmid) break;
            result++;
        }
        cout << result << "\n";
    }

    return 0;
}