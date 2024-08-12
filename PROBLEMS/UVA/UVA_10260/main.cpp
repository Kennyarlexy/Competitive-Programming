#include <bits/stdc++.h>
#define ll long long
using namespace std;

unordered_set<char> A[7] = {
    {},
    {'B', 'F', 'P', 'V'},
    {'C', 'G', 'J', 'K', 'Q', 'S', 'X', 'Z'},
    {'D', 'T'},
    {'L'},
    {'M', 'N'},
    {'R'}
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while (cin >> s) {
        ll prev = -1;
        for (ll i = 0; i < s.length(); i++) {
            bool others = true;
            for (ll j = 1; j <= 6; j++) {
                if (A[j].count(s[i])) {
                    if (j != prev) cout << j;
                    prev = j;
                    others = false;
                    break;
                }
            }
            if (others) prev = -1;
        }
        cout << "\n";
    }
    
    return 0;
}

/*
KHAWN
PFISTER
BOBBY
CAN
CON
GONE
*/