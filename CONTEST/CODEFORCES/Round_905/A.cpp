#include <bits/stdc++.h>
#define ll long long
using namespace std;

string transform(string n) {
    for (auto& ch : n) {
        if (ch == '0') ch = '9'+ 1;
    }
    return n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string n; cin >> n;
        n = transform(n);
        int ans = 4;
        char cur = '1';
        for (int i = 0; i < 4; i++) {
            ans += abs(n[i] - cur);
            cur = n[i];
        }
        cout << ans << "\n";
    }

    
    return 0;
}

