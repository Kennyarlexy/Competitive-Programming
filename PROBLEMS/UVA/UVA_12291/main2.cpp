#include <bits/stdc++.h>
#define ll long long
using namespace std;

char A[15][15];
char B[15][15];

struct Sides {
    ll left, top, bot, right, width, height;
    Sides() {
        left = LONG_LONG_MAX;
        top = LONG_LONG_MAX;
        bot = 0;
        right = 0;
    }
};

bool f(Sides SA, Sides SB) {
    if (SA.width < SB.width || SA.height < SB.height)
        return false;
    
    ll _A[15][15];
    for (ll r = SA.top; r <= SA.bot; r++) {
        for (ll c = SA.left; c <= SA.right; c++) {
            _A[r][c] = A[r][c];
        }
    }
    
    ll offset_r = SA.top - SB.top;
    ll offset_c = SA.left - SB.left;

    for (ll rB = SB.top; rB <= SB.bot; rB++) {
        for (ll cB = SB.left; cB <= SB.right; cB++) {
            ll rA = rB+offset_r;
            ll cA = cB+offset_c;
            if (B[rB][cB] == _A[rA][cA]) {
                _A[rA][cA] = '.';
            } else if (B[rB][cB] == '*') return false;
        }
    }

    offset_r = SA.bot - SB.bot;
    offset_c = SA.right - SB.right;

    for (ll rB = SB.bot; rB >= SB.top; rB--) {
        for (ll cB = SB.right; cB >= SB.left; cB--) {
            ll rA = rB+offset_r;
            ll cA = cB+offset_c;
            if (B[rB][cB] == _A[rA][cA]) {
                _A[rA][cA] = '.';
            } else if (B[rB][cB] == '*') return false;
        }
    }

    for (ll r = SA.top; r <= SA.bot; r++) {
        for (ll c = SA.left; c <= SA.right; c++) {
            if (_A[r][c] == '*') return false;
        }
    }
    return true;
}

void flip(Sides SA, Sides SB) {
    for (ll r = SA.top; r <= SA.bot; r++) {
        ll c1 = SA.left, c2 = SA.right;
        while (c1 < c2) {
            swap(A[r][c1], A[r][c2]);
            c1++, c2--;
        }
    }

    for (ll r = SB.top; r <= SB.bot; r++) {
        ll c1 = SB.left, c2 = SB.right;
        while (c1 < c2) {
            swap(B[r][c1], B[r][c2]);
            c1++, c2--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        Sides SA;
        for (ll r = 1; r <= n; r++) {
            for (ll c = 1; c <= n; c++) {
                cin >> A[r][c];
                if (A[r][c] == '*') {
                    SA.left = min(SA.left, c);
                    SA.right = max(SA.right, c);
                    SA.top = min(SA.top, r);
                    SA.bot = max(SA.bot, r);
                }
            }
        }
        SA.width = SA.right - SA.left + 1;
        SA.height = SA.bot - SA.top + 1;

        Sides SB;
        for (ll r = 1; r <= m; r++) {
            for (ll c = 1; c <= m; c++) {
                cin >> B[r][c];
                if (B[r][c] == '*') {
                    SB.left = min(SB.left, c);
                    SB.right = max(SB.right, c);
                    SB.top = min(SB.top, r);
                    SB.bot = max(SB.bot, r);
                }
            }
        }
        SB.width = SB.right - SB.left + 1;
        SB.height = SB.bot - SB.top + 1;


        if (f(SA, SB)) cout << "1\n";
        else {
            flip(SA, SB);
            if (f(SA, SB)) cout << "1\n";
            else cout << "0\n";
        }
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

2 1
**
..
*

2 2
**
**
**
.*
0 0
*/