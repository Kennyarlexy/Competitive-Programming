#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<char, char> MP = {
    {'p', 'q'},
    {'q', 'p'},
    {'w', 'w'}
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string s; cin >> s;
        reverse(s.begin(), s.end());
        for (auto ch : s) {
            cout << MP[ch];
        }
        cout << "\n";
    }
    
    return 0;
}