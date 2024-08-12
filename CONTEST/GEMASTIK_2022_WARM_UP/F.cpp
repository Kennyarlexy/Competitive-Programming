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
    string S; cin >> S;
    ll Q; cin >> Q;
    for (ll q = 1; q <= Q; q++) {
        ll type; cin >> type;
        if (type == 0) {
            ll a, b; cin >> a >> b;
            ll end = b;
            ll len = 0;
            while (a <= end) {
                if (S[a++] ==   S[b--]) len++;
                else break;
            }
            cout << len << "\n";
        } else {
            ll x; cin >> x;
            char c; cin >> c;
            S[x] = c;
        }
    }

    return 0;
}