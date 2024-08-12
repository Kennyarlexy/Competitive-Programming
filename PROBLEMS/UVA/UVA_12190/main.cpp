#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

pair<ll, ll> C[3] = {
    {100, 2},
    {9900, 3},
    {990000, 5}
};

ll f(ll X) {
    ll bill = 0;
    for (int i = 0; i < 3; i++) {
        ll d = min(C[i].fi, X);
        bill += d*C[i].se;
        X -= d;
    }

    if (X > 0) bill += X*7;
    return bill;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll A, B;
    while (cin >> A >> B && A && B) {
        ll Z = 0;
        for (int i = 0; i < 3; i++) {
            if (A == 0) break;
            ll d = min(C[i].fi * C[i].se, A);
            Z += d/C[i].se;
            A -= d;
        }

        // assert(A % 7 == 0);
        if (A > 0) Z += A/7;

        ll X = 0;
        for (ll step = Z; step > 0; step /= 2) {
            while (X + step <= Z && f(Z - (X+step)) - f(X+step) >= B) X += step;
        }

        ll ans = f(X);
        cout << ans << "\n";
    }
    
    return 0;
}