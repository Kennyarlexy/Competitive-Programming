#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    //use ll when possible!

    //finding substr
    string s, t;
    getline(cin, s) >> t;
    ll i = 0;
    while (true) {
        ll j = s.find(t, i);
        if (j == -1) break;
        cout << j << "\n";
        i = j + 1;
    }
    
    return 0;
}