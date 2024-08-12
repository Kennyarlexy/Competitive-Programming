#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

string s; 
bool isPalindrome(ll l, ll r) {
    while (l <= r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}

int main() {
    fast_io();
    //use ll when possible!
    cin >> s;
    for (ll m = 0; m < s.length()-1; m++) {
        if (isPalindrome(0, m) && isPalindrome(m+1, s.length()-1)) {
            cout << s.substr(0, m+1) << " " << s.substr(m+1) << "\n";
            return 0;
        }
    }
    
    cout << "NO\n";

    return 0;
}