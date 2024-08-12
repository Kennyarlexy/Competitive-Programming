#include <bits/stdc++.h>
#define ll long long

using namespace std;
string s; ll a, b;
ll A = 0, B = 0, cnt = 0;
multiset<char> MS;

void f(ll i, char digit) {
    bool correct = false;
    ll tA = A, tB = B;
    if (MS.find(digit) != MS.end()) {
        if (digit == s[i]) A++;
        else B++;
        MS.erase(MS.find(digit));
        correct = true;
    }

    if (i < s.length()-1) {
        for (char next = '1'; next <= '9'; next++) {
            f(i+1, next);
        }
    } 
    else if (A == a && B == b) cnt++;

    if (correct) {
        MS.insert(digit);
        A = tA;
        B = tB;
    }
    if (i == s.length()-1) return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        MS = {};
        A = 0, B = 0, cnt = 0;
        cin >> s >> a >> b;
        for (ll i = 0; i < s.length(); i++) {
            MS.insert(s[i]);
        }

        for (char ch = '1'; ch <= '9'; ch++) {
            A = 0, B = 0;
            f(0, ch);
        }

        cout << cnt << "\n";
    }
    
    return 0;
}