#include <bits/stdc++.h>
#define ll long long
#define x first 
#define y second
using namespace std;

pair<ll, ll> A[1005];
const double EPS = 1e-10;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, d;
    int t = 0;
    while (cin >> n >> d && n && d) {
        t++;
        ll mx_y = LLONG_MIN;
        for (int i = 1; i <= n; i++) {
            cin >> A[i].x >> A[i].y;
            mx_y = max(mx_y, A[i].y);
        }

        if (mx_y > d) {
            cout << "Case " << t << ": -1\n";
            continue;
        }

        sort(A+1, A+1+n);

        ll cnt = 0;
        for (int i = 1; i <= n; i++) {
            double L = -1e9, R = 1e9;
            while (i <= n) {
                double dx = sqrt(d*d - A[i].y*A[i].y);
                double l = A[i].x - dx, r = A[i].x + dx;

                // double nL = (L + EPS < l) ? l : nL;
                // double nR = (r + EPS < R) ? r : nR;
                double nL = max(L, l), nR = min(R, r);
                
                if (nL > nR) break;

                L = nL, R = nR;
                i++;
            }
            i--;
            cnt++;
        }

        cout << "Case " << t << ": " << cnt << "\n";
    }
    
    return 0;
}

/*
3 2
1 2
-3 1
2 1

1 2
0 2
0 0



7 5
3 5
0 4
6 4
13 5
10 4
16 4
17 4

0 0
*/