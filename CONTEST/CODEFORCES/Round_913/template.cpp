#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string pos; cin >> pos;
        for (int i = 1; i <= 8; i++) {
            if (pos[1] - '0' == i) continue;
            cout << pos[0] << i << "\n";
        }

        for (char ch = 'a'; ch <= 'h'; ch++) {
            if (pos[0] == ch) continue;
            cout << ch << pos[1] << "\n";
        }
    }
    
    return 0;
}