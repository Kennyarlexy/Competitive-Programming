#include <bits/stdc++.h>
#define ll long long
#define P complex<ll>
#define X real()
#define Y imag()
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll xm, ym, xp, yp, xk, yk;
        cin >> xm >> ym >> xp >> yp >> xk >> yk;
P u = {xm, ym};
P v = {xp, yp};
        P w = {xk, yk};

        P a = v - u;
        P b = w - u;

ll cross_product = (conj(a)*b).Y;
        cout << "Case #" << t << ": rasi "; 
        if (cross_product > 0) {
            cout << "kucing\n";
        } else if (cross_product < 0) {
            cout << "anjing\n";
        } else {
            cout << "ular\n";
        }
    }
    
    return 0;
}