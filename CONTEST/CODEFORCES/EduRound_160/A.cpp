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
        string ab; cin >> ab;

        bool OK = false;
        for (int i = 1; i < ab.length(); i++) {
            string a = ab.substr(0, i);
            string b = ab.substr(i);

            if (b[0] == '0') continue;

            if (stoi(a) < stoi(b)) {
                cout << a << " " << b << "\n";
                OK = true;
                break;
            }
        }

        if (!OK) cout << "-1\n";
    }
    
    return 0;
}