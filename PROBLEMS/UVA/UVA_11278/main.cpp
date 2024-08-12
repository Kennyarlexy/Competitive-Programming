#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Position {
    ll s, r, c;
};

string Q[2][4] = {
    {
        "`1234567890-=",
        "qwertyuiop[]\\",
        "asdfghjkl;'",
        "zxcvbnm,./"
    },
    {
        "~!@#$%^&*()_+",
        "QWERTYUIOP{}|",
        "ASDFGHJKL:\"",
        "ZXCVBNM<>?"
    }
};


string D[2][4] = {
    {
        "`123qjlmfp/[]",
        "456.orsuyb;=\\",
        "789aehtdck-",
        "0zx,inwvg'"
    },
    {
        "~!@#QJLMFP?{}",
        "$%^>ORSUYB:+|",
        "&*(AEHTDCK_",
        ")ZX<INWVG\""
    }
};

Position pos[1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (ll s = 0; s < 2; s++) {
        for (ll r = 0; r < 4; r++) {
            for (ll c = 0; c < Q[s][r].length(); c++) {
                pos[Q[s][r][c]] = {s, r, c};
            } 
        }
    }
    
    string line;
    while (getline(cin, line)) {
        string res;
        for (auto& ch : line) {
            if (ch == ' ') res.push_back(' ');
            else {
                auto s = pos[ch].s, r = pos[ch].r, c = pos[ch].c;
                res.push_back(D[s][r][c]);
            }
        }
        cout << res << "\n";
    }
    
    return 0;
}