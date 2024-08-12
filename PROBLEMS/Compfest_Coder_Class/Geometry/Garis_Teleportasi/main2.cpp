#define _USE_MATH_DEFINES // this comes first
#include <bits/stdc++.h>
#define ll long long
#define P complex<long double> // but use ll when possible
#define X real()
#define Y imag()
using namespace std;

long double cross(P u, P v) {
    return (conj(u)*v).Y;
}

long double dot(P u, P v) {
    return (conj(u)*v).X;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll x, y; cin >> x >> y;
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    P p = {x, y};
    P s1 = {x1, y1};
    P s2 = {x2, y2};

    long double k1 = dot(s1-p, s2-s1);
    long double k2 = dot(s2-p, s1-s2);
    // long double k3 = cross(s1-s2, p);

// cout << "k1 = " << k1 << "   k2 = " << k2 << "\n";

    if (abs(s2-s1) == 0 || k1*k2 < 0) {
        long double d = min(abs(s1-p), abs(s2-p));
        cout << fixed << setprecision(9) << d << "\n";
    } else {
        long double d = cross(s1-p, s2-p) / abs(s2-s1);
        cout << fixed << setprecision(9) << abs(d) << "\n";
    }
    
    return 0;
}