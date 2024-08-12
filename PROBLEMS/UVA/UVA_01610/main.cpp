#include <bits/stdc++.h>
#define ll long long
using namespace std;

string A[1005];
string f(string s, string t) {
    ll len = max(s.length(), t.length());
    string res;
    for (ll i = 0; i < len; i++) {
        bool OK = false;
        if (i < s.length()-1) {
            if (i < t.length()-1 && s[i]+1 <= t[i]) {
                OK = true;
                res.push_back(s[i]+1);
            } 
            else if (i < t.length() && s[i]+1 < t[i]) {
                OK = true;
                res.push_back(s[i]+1);
            }
            else if (i >= t.length() && s[i] != 'Z') {
                OK = true;
                res.push_back(s[i]+1);
            }
        }

        if (OK || i >= s.length()) break;
        else {
            res.push_back(s[i]);
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        for (ll i = 1; i <= n; i++) {
            cin >> A[i];
        }

        sort(A+1, A+n+1);

        ll im = (n+1)/2;
        string res = f(A[im], A[im+1]);
        cout << res << "\n";
    }
    
    return 0;
}

/*
4
FRED
SAM
JOE
MARGARET
2
FRED
FREDDIE
2
JOSEPHINE
JERRY
2
LARHONDA
LARSEN
0

2
FAGGG
FB
2
FAGGG
FBB
0

2
FFFAFFF
FFFCFFF
0

2
FFFA
FFFB
0

2
FFFA
FG
0

2
FFZA
FG
0

2
ABXA
ABZ
0
*/