#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

double A[1000005];

int main() {
    fast_io();
    //use ll when possible!
    ll p, a, b, c, d, n;
    while (cin >> p >> a >> b >> c >> d >> n) {
        for (ll k = 1; k <= n; k++) {
            A[k] = (double) p*(sin(a*k + b) + cos(c*k + d) + 2);
        }
        double res = 0;
        double Max = A[1];
        for (ll k = 2; k <= n; k++) {
            res = max(res, Max - A[k]);
            Max = max(Max, A[k]);
        }
        cout << fixed << setprecision(8) << res << "\n";
    }

    return 0;
}