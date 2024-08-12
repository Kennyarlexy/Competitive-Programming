#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while (getline(cin, s)) {
        list<char> res;
        auto itr = res.end();
        for (auto& ch : s) {
            if (ch == '[') {
                itr = res.begin();
                continue;
            } else if (ch == ']') {
                itr = res.end();
                continue;
            }

            res.insert(itr, ch);
        }

        for (auto& ch : res) {
            cout << ch;
        }
        cout << "\n";
    }
    
    return 0;
}