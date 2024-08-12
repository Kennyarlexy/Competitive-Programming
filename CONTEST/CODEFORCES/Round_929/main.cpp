#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll z[105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s = "ABCABCABAB";
    ll n = s.length();
    ll x = 0, y = 0;
    z[0] = n;
    for (int i = 1; i < n; i++) {
        z[i] = (i > y ? 0 : min(y-i+1, z[i-x]));

        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            z[i]++;
        }
        if (i+z[i]-1 > y) {
            x = i, y = i+z[i]-1;
        }
    }

    for (auto ch : s) {
        cout << ch << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << z[i] << " \n"[i==n-1];
    }

    
    return 0;
}