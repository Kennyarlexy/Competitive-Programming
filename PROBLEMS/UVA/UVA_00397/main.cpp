#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while (getline(cin, s)) {
        ll i = -1;
        while (i < s.length()) {
            i++;
            if (s[i] == ' ') continue;
            if (isdigit(s[i])) {
                ll l = i, r = i;
                string A[3];
                ll j = 1;
                char op = 0;
                while (r < s.length() && j <= 2) {
                    if (s[r] != ' ') {
                        
                    }
                }
                
                break;
            }
        }
    }
    
    return 0;
}