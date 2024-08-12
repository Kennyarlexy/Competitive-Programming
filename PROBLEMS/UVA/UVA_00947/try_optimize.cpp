#include <bits/stdc++.h>
#define ll long long

using namespace std;
string s; ll a, b, cnt = 0;
multiset<char> MS;

void f(ll i, ll CC, ll CW) {
    if (i == s.length()) {
        if (CC == a && CW == b) cnt++;
        return;
    }
    
    for (char ch = '1'; ch <= '9'; ch++) {
        if ()
        
        // if (MS.find(ch) != MS.end()) {
        //     MS.erase(MS.find(ch));
        //     if (ch == s[i]) f(i+1, CC+1, CW);
        //     else f(i+1, CC, CW+1);
        //     MS.insert(ch);
        // } else {
        //     f(i+1, CC, CW);
        // }
    }
}

// string code;

// void f() {
//     if (code.length() == s.length()) {
//         multiset<char> MS;
//         for (auto& ch : code) {
//             MS.insert(ch);
//         }
        
//         ll CC = 0, CW = 0;
//         for (ll i = 0; i < s.length(); i++) {
//             if (s[i] == code[i]) {
//                 CC++;
//                 MS.erase(MS.find(s[i]));
//             }
//         }

//         for (ll i = 0; i < s.length(); i++) {
//             if (MS.find(s[i]) != MS.end() && s[i] != code[i]) {
//                 CW++;
//                 MS.erase(MS.find(s[i]));
//             }
//         }
//         if (CC == a && CW == b) cnt++;
//         return;
//     }

//     for (char ch = '1'; ch <= '9'; ch++) {
//         code.push_back(ch);
//         f();
//         code.pop_back();
//     }
// }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        MS = {};
        cnt = 0;
        cin >> s >> a >> b;
        for (auto& ch : s) {
            MS.insert(ch);
        }

        f(0, 0, 0);

        cout << cnt << "\n";
    }
    
    return 0;
}