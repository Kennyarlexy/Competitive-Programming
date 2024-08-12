#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll n; cin >> n;
        if (n % 2 == 1) n++;

        ll res;
        if (n <= 8) res = 26;
        else if (n <= 10) res = 30;
        else if (n <= 12) res = 34;
        else if (n <= 14) res = 42;
        else if (n % 10 == 2) res = (n-12)*2 + 34;
        else if (n % 10 == 4) res = (n-24)*2 + 58;
        else if (n % 10 == 6) res = (n-16)*2 + 42;
        else if (n % 10 == 8) res = (n-18)*2 + 46;
        else res = n*2 + 10;
        
        cout << res % 2022 << "\n";
    }
    
    return 0;
}