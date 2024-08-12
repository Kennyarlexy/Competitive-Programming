#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<string> A;
vector<string> B;

struct Point {
    ll r, c;
    Point(ll _r, ll _c) {
        r = _r;
        c = _c;
    }
};

void print(vector<string> &A, ll n) {
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cout << A[i][j];
        }
        cout << "\n";
    }
}

bool f(ll r, ll c, vector<string> A_copy, vector<Point> &P, ll d, ll n) {
    for (auto& p : P) {
        ll r1 = r+p.r;
        ll c1 = c+p.c;
        if (r1 < 0 || r1 >= n) return false;
        if (c1 < 0 || c1 >= n) return false;
        if (A_copy[r1][c1] == '*') {
            A_copy[r1][c1] = '.';
        } else {
            return false;
        }
    }

    if (d == 2) return true;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (A_copy[i][j] == '*') {
                if (f(i, j, A_copy, P, d+1, n)) return true;
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    auto __time_1 = chrono::high_resolution_clock::now();
    A.resize(20); B.resize(20);
    
    ll n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        ll cntA = 0, cntB = 0;
        for (ll i = 0; i < n; i++) {
            cin >> A[i];
            for (ll j = 0; j < n; j++) {
                if (A[i][j] == '*') cntA++;
            }
        }

        // print(A, n);

        Point p(-1, -1);
        vector<Point> P;
        for (ll i = 0; i < m; i++) {
            cin >> B[i];
            for (ll j = 0; j < m; j++) {
                if (B[i][j] == '*') {
                    if (p.r == -1 && p.c == -1) {
                        p.r = i; p.c = j;
                    }
                    P.emplace_back(i-p.r, j-p.c);
                    cntB++;
                }
            }
        }

        // print(B, m);

        if (n == 0 || m == 0) {
            cout << 0 << "\n";
            continue;
        }
        // print(B, m);

        if (2*cntB != cntA) {
            cout << 0 << "\n";
        } else {
            bool OK = false;
            for (ll i = 0; i < n; i++) {
                for (ll j = 0; j < n; j++) {
                    if (A[i][j] == '*' && f(i, j, A, P, 1, n)) {
                        OK = true;
                        break;
                    }
                }
            }

            cout << OK << "\n";
        }
    }
    auto __time_2 = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> exe_time_ms = __time_2 - __time_1;
    // cout << exe_time_ms.count() << "ms\n";
    
    return 0;
}

/*
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
4 3
.**.
****
***.
....
**.
.**
...
0 0
*/