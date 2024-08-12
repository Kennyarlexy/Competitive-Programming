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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ld x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    P a = {x1, y1}, b = {x2, y2}, c = {x3, y3}, d = {x4, y4};

    P u = b-a, v = d-c;

    if (u.X == 0 || v.X == 0) {
        if (v.X == 0) {
            swap(u, v);
            swap(a, c);
            swap(b, d);
        }
        
        // ab is vertical, cd is not
        if (case_2(a, b, c, d) || case_3(a, b, c, d)) {
            ld g1 = grad(c, d);
            ld c1 = find_c(g1, c);

            ld x_tabrak = a.X;
            ld y_tabrak = g1*x_tabrak + c1;
            cout << fixed << setprecision(9) << x_tabrak << " " << y_tabrak << "\n";
        } else {
            cout << "-1 -1\n";
        }
        
        return 0; // done
    }

    if (case_2(a, b, c, d) || case_3(a, b, c, d)) {
        ld g1 = grad(a, b), g2 = grad(c, d);
        ld c1 = find_c(g1, a), c2 = find_c(g2, c);

        ld x_tabrak = (c2-c1) / (g1-g2);
        ld y_tabrak = g1*x_tabrak + c1;

        cout << fixed << setprecision(9) << x_tabrak << " " << y_tabrak << "\n";
    } else {
        cout << "-1 -1\n";
    }


    return 0;
}