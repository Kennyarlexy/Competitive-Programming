#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second 
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll l = 1, r = 1000000;
    while (l != r) {
        ll m = (l+r) / 2;
        cout << m << "\n" << flush;
        string s; cin >> s;
        if (s == "<") r = m-1;
        else l = m;
    }
    cout << "! " << l << "\n" << flush;
    
    return 0;
}