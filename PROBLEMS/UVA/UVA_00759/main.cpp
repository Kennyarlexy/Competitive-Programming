#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<string, ll> MP = {
    {"I", 1},
    {"V", 5},
    {"X", 10},
    {"L", 50},
    {"C", 100},
    {"D", 500},
    {"M", 1000},
    {"IV", 4},
    {"IX", 9},
    {"XL", 40},
    {"XC", 90},
    {"CD", 400},
    {"CM", 900}
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while (cin >> s) {
        ll cnt = 1, cnt_V = 0, cnt_L = 0, cnt_D = 0;
        bool OK = true;
        for (ll i = 0; i < s.length(); i++) {
            if (i > 0) {
                if (s[i] == s[i-1]) cnt++;
                else cnt = 1;
            }

            if (cnt > 3) {
                OK = false;
                break;
            }
        }

        ll i = 0, n = s.length();
        ll res = 0;
        ll limit = 1000;
        while (OK && i < n) {
            string dd = s.substr(i, 2), d = s.substr(i, 1);
            if (i < n-1 && MP.find(dd) != MP.end() && MP[dd] <= limit) {
                res += MP[dd];
                limit = pow(10, to_string(MP[dd]).length()-1) - 1;
                i += 2;
            } else if (MP.find(d) != MP.end() && MP[d] <= limit) {
                res += MP[d];
                limit = pow(10, to_string(MP[d]).length()-1);
                i++;
            } else {
                OK = false;
            }
        }

        if (OK) cout << res << "\n";
        else cout << "This is not a valid number\n";
    }
    
    return 0;
}

/*
VV
VIV
IVI
IIV
IXI
IXX
XXI
IIX

XXXX
VVVV
XXX
VVV
XX
VV
X
V


VIII
XIII
VVIII
XXIII

VIV
XIX
IVI
IXI

IIII
III

IIIX
IIX
IX
X

XCX
*/