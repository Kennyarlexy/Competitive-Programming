#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    while (true) {
        cin >> n;
        if (n == 0) break;

        ll a = 0, b = 0;
        ll cnt = 0;
        for (ll i = 0; i < 32; i++) {
            if (n & (1LL << i)) {
                cnt++;
                if (cnt % 2 == 1) a |= (1LL << i);
                else b |= (1LL << i);
            }
        }
        cout << a << " " << b << "\n";
    }
    
    return 0;
}