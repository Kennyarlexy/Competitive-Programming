#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
#define double long double
using namespace std;

const double EPS = 1e-7;
const double EPS_2 = 1e-9;

pair<double, double> A[105];

double f(double hs, int n) {
    double dx = 0;
    for (int i = 1; i <= n; i++) {
        dx += A[i].fi * hs * A[i].se;
    }

    return dx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double x, y; cin >> x >> y;
    int n; cin >> n;
    double H = 0;
    for (int i = 1; i <= n; i++) {
        double l, u, fi;
        cin >> l >> u >> fi;
        A[i] = {u - l, fi};
        H += u - l;
    }

    double _x = abs(x);
    double hs = 1e-9;
    for (double step = 1e9; step > EPS_2; step /= 2) {
        while (f(hs+step, n) + (y-H)*(hs+step) - _x <= 0) hs += step;
    }

    double ans = (x < 0) ? -hs : hs;
    // double ans = hs;

    cout << fixed << setprecision(10) << ans << "\n";
    
    return 0;
}

/*
-100 100
3
0 20 2.0000000000
50 100 0.1000000000
20 50 0.2000000000

10000000 1
1
0 1 0.1

1 100000000
1
0 100000000 10
*/