#include <bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

ll mod = 1e9;

ll modexp(ll a, ll b) {
    if (b == 0) return 1;

    ll root = modexp(a, b/2);
    ll res = root * root;
    if (b & 1) res = (res % mod) * a;
    return res % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ld a, b; cin >> a >> b;
        if (b / a * log2l(a) > log2l(b)) {
            cout << modexp((ll) a % mod, b) << "\n";
        } else {
            cout << modexp((ll) b % mod, a) << "\n";
        }
    }
    
    return 0;
}