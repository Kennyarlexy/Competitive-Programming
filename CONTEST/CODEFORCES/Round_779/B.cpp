#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll compute(ll any, ll x) {
    ll fact_any = 1;
    while (any > 1) {
        fact_any *= any;
        fact_any %= 998244353;
        any--;
    }
    ll fact_x = 1;
    while (x > 1) {
        fact_x *= x;
        fact_x %= 998244353;
        x--;
    }
    return ((fact_any*fact_x) % 998244353);
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll n; cin >> n;
        if (n % 2 != 0 || n == 1) {
            cout << "0\n";
        } else {
            ll any = n/2;
            ll x = n - (any+1);
            cout << (n/2 * compute(any, x)) % 998244353 << "\n";
        }
    }

    return 0;
}