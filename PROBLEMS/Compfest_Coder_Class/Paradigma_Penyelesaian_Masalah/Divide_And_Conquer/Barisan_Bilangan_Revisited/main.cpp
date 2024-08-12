#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, A, B;
ll LCM;

ll f(ll x) {
    ll n = x/A + x/B - x/LCM;
    return n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> A >> B;
    LCM = lcm(A, B);

    ll x = 1e14;
    for (ll step = x; step > 0; step /= 2) {
        while (x - step >= 0 && f(x - step) >= N) x -= step;
    }

    cout << x << "\n";
    
    return 0;
}