#include <bits/stdc++.h>
#define ll long long
#define Point pair<ll, ll>
#define fi first
#define se second
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        string a; cin >> a;
        string b = a;
        reverse(b.begin(), b.end());
        if (a < b) {
            ll k = (n % 2 == 1 ? n-1 : n);
            n -= k;
            cout << a;
            if (n > 0) cout << b;
            cout << "\n";
        } else if (b < a) {
            ll k = (n % 2 == 0 ? n-1 : n);
            n -= k;
            cout << b;
            if (n > 0) cout << a;
            cout << "\n";
        } else {
            cout << a << "\n";
        }
    }
    
    return 0;
}