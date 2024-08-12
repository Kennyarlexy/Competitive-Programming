#define _USE_MATH_DEFINES // this comes first
#include <bits/stdc++.h>
#define ll long long
#define P complex<long double> // but use ll when possible
#define X real()
#define Y imag()
#define ld long double
using namespace std;

ld grad(P a, P b) {
    P ab = b - a;
    return ab.Y / ab.X;
}

ld find_c(ld g, P a) {
    ld c = a.Y - g*a.X;
    return c;
}

ld cross(P u, P v) {
    return (conj(u)*v).Y;
}

ld dot(P u, P v) {
    return (conj(u)*v).X;
}

// line intersection -> case_1, case_2, case_3
bool case_1(P a, P b, P c, P d) {
    if (cross(b-a, c-b) != 0) return false;
    if (cross(b-a, d-b) != 0) return false;
    
    return max(a.X, c.X) <= min(b.X, d.X);
}

bool case_2(P a, P b, P c, P d) {
    // fix ab
    if (cross(b-a, c-b) == 0 || cross(b-a, d-b) == 0) return true;

    // fix cd
    if (cross(d-c, a-d) == 0 || cross(d-c, b-d) == 0) return true;

    return false;
}

bool case_3(P a, P b, P c, P d) {
    // fix ab
    if ((cross(b-a, c-b) < 0) == (cross(b-a, d-b) < 0)) return false;

    // fix cd
    if ((cross(d-c, a-d) < 0) == (cross(d-c, b-d) < 0)) return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll x1 = 4, y1 = 2, x2 = 3, y2 = -1;
        
    P u = {x1, y1};
    P v = {x2, y2};

    P uv = v - u;
    ld length = abs(uv); // abs(v - u)
    ld angle = arg(u); // from x axis (radiant)
    P w = polar(10.0, 0.5*M_PI); // len = 10, angle = 0.5*PHI
    
    cout << "length = " << length << "\n";
    cout << "angle = " << angle << "\n";
    cout << "w = {" << w.X << ", " << w.Y << "}\n";
    return 0;
}