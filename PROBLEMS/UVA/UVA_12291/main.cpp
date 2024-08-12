#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m;
char A[15][15];
char B[15][15];
char temp[15][15];
ll l1, t1, r1, b1;
ll l2, t2, r2, b2;

bool f() {
    ll w1 = r1-l1+1;
    ll h1 = b1-t1+1;
    ll w2 = r2-l2+1;
    ll h2 = b2-t2+1;
    if (w1 < w2 || h1 < h2) return false;

    for (ll r = 1; r <= n; r++) {
        for (ll c = 1; c <= n; c++) {
            A[r][c] = temp[r][c];
        }
    }

    ll R1 = t1, R2 = t2;
    while (R2 <= b2) {
        ll C1 = l1, C2 = l2;
        while (C2 <= r2) {
            if (B[R2][C2] == '*' && A[R1][C1] != '*') return false;

            if (B[R2][C2] == '*') A[R1][C1] = '.';
            C1++, C2++;
        }
        R1++, R2++;
    }

    R1 = b1, R2 = b2;
    while (R2 >= t2) {
        ll C1 = r1, C2 = r2;
        while (C2 >= l2) {
            if (B[R2][C2] == '*' && A[R1][C1] != '*') return false;

            if (B[R2][C2] == '*') A[R1][C1] = '.';
            C1--, C2--;
        }
        R1--, R2--;
    }

    for (ll r = 1; r <= n; r++) {
        for (ll c = 1; c <= n; c++) {
            if (A[r][c] == '*') return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        l1 = 1e9, t1 = 1e9, r1 = 0, b1 = 0;
        for (ll r = 1; r <= n; r++) {
            for (ll c = 1; c <= n; c++) {
                cin >> temp[r][c];
                if (temp[r][c] == '*') {
                    l1 = min(l1, c);
                    t1 = min(t1, r);
                    r1 = max(r1, c);
                    b1 = max(b1, r);
                }
            }
        }

        l2 = 1e9, t2 = 1e9, r2 = 0, b2 = 0;
        for (ll r = 1; r <= m; r++) {
            for (ll c = 1; c <= m; c++) {
                cin >> B[r][c];
                if (B[r][c] == '*') {
                    l2 = min(l2, c);
                    t2 = min(t2, r);
                    r2 = max(r2, c);
                    b2 = max(b2, r);
                }
            }
        }

        if (f()) cout << 1 << "\n";
        else {
            for (ll r = t1; r <= b1; r++) {
                ll cl = l1, cr = r1;
                while (cl < cr) {
                    swap(temp[r][cl], temp[r][cr]);
                    cl++, cr--;
                }
            }

            for (ll r = t2; r <= b2; r++) {
                ll cl = l2, cr = r2;
                while (cl < cr) {
                    swap(B[r][cl], B[r][cr]);
                    cl++, cr--;
                }
            }

            if (f()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }

        // for debug only-----------
        // for (ll r = t1; r <= b1; r++) {
        //     for (ll c = l1; c <= r1; c++) {
        //         cout << temp[r][c];
        //     }
        //     cout << "\n";
        // }

        // for (ll r = t2; r <= b2; r++) {
        //     for (ll c = l2; c <= r2; c++) {
        //         cout << B[r][c];
        //     }
        //     cout << "\n";
        // }

        // for (ll r = 1; r <= n; r++) {
        //     for (ll c = 1; c <= n; c++) {
        //         cout << A[r][c];
        //     }
        //     cout << "\n";
        // }
    }
    
    return 0;
}

/*
4 3
.**.
****
.**.
....
.**
**.
...
4 3
.**.
****
.**.
....
**.
.**
...
0 0

4 3
.**.
****
.**.
....
**.
.**
...
3 3
***
*.*
***
*..
*..
**.
4 2
****
....
....
....
*.
*.
0 0
*/