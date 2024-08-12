#include <bits/stdc++.h>
#define ll long long
#define le first
#define ri second
using namespace std;

const double EPS = 1e-10;
pair<double, double> A[10005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n; double l, w;
    while (cin >> n >> l >> w) {
        for (int i = 1; i <= n; i++) {
            double x, r; cin >> x >> r;
            double h = w/2;
            double d = sqrt(r*r - h*h);
            A[i] = {x-d, x+d};
        }

        sort(A+1, A+1+n);

        double right = 0;
        int cnt = 0;
        double x = 0;
        bool OK = true;
        for (int i = 1; i <= n; i++) {
            if (right + EPS < A[i].le) {
                cnt++;
                right = x;
            }

            if (right + EPS < A[i].le) {
                OK = false;
                break;
            }

            if (x + EPS < A[i].ri) x = A[i].ri;
        }

        if (!OK) cout << "-1\n";
        else {
            if (right < l) {
                cnt++;
                right = x;
            }
            if (right < l) cout << "-1\n";
            else cout << cnt << "\n";
        }
    }
    
    return 0;
}

/*
3 5 0
0 2
3 2
5 2
*/