#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string s; cin >> s;
        int x = 0;
        for (auto ch : s) {
            if (ch == 'A') x++;
        }

        int y = s.length() - x;
        if (x > y) cout << "A\n";
        else cout << "B\n";
    }
    
    return 0;
}