#include <bits/stdc++.h>
#define ll long long
using namespace std;

char A[15][15];
char B[15][15];
char _A[15][15];
char _B[15][15];
char _C[15][15]; // combined

struct Sides {
    ll top, bot, left, right;
    Sides() {
        top = LONG_LONG_MAX;
        bot = 0;
        left = LONG_LONG_MAX;
        right = 0;
    }
};

void input(char G[15][15], ll size, Sides& S, ll &cnt) {
    for (ll r = 0; r < size; r++) {
        for (ll c = 0; c < size; c++) {
            cin >> G[r][c];
            if (G[r][c] == '*') {
                cnt++;
                S.top = min(S.top, r);
                S.bot = max(S.bot, r);
                S.left = min(S.left, c);
                S.right = max(S.right, c);
            }
        }
    }
}

void debugSide(Sides &S) {
    cout << S.top << " " << S.bot << " " << S.left << " " << S.right << "\n";
}

void crop(char G[15][15], char _G[15][15], Sides &S) {
    for (ll r = S.top; r <= S.bot; r++) {
        for (ll c = S.left; c <= S.right; c++) {
            _G[r-S.top][c-S.left] = G[r][c];
        }
    }

    auto temp = S;
    S.top = 0;
    S.bot = temp.bot-temp.top;
    S.left = 0;
    S.right = temp.right-temp.left;
}

void f(char G[15][15], char _G[15][15], Sides &S, ll offset_r, ll offset_c) {
    for (ll r = 0; r <= S.bot; r++) {
        for (ll c = 0; c <= S.right; c++) {
            if (G[r][c] == '*') {
                _G[r+offset_r][c+offset_c] = G[r][c];
            }
        }
    }
}

void reset(char G[15][15]) {
    for (ll r = 0; r < 10; r++) {
        for (ll c = 0; c < 10; c++) {
            G[r][c] = '.';
        }
    }
}

bool match(char G[15][15], char H[15][15], Sides &S) {
    for (ll r = 0; r <= S.bot; r++) {
        for (ll c = 0; c <= S.right; c++) {
            if (G[r][c] != H[r][c]) return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        Sides SA, SB;
        ll cntA = 0, cntB = 0;
        input(A, n, SA, cntA);
        input(B, m, SB, cntB);
        // debugSide(SA);
        // debugSide(SB);
        if (2*cntB != cntA) {
            cout << "0\n";
        } else {
            crop(A, _A, SA);
            crop(B, _B, SB);
            // for (ll r = 0; r <= SA.bot; r++) {
            //     for (ll c = 0; c <= SA.right; c++) {
            //         cout << _A[r][c];
            //     }
            //     cout << "\n";
            // }
            reset(_C);
            // debugSide(SA);
            // debugSide(SB);
            f(_B, _C, SB, 0, 0);
            f(_B, _C, SB, SA.bot-SB.bot, SA.right-SB.right);
            if (match(_A, _C, SA)) {
                cout << "1\n";
            } else {
                reset(_C);
                f(_B, _C, SB, 0, SA.right-SB.right);
                f(_B, _C, SB, SA.bot-SB.bot, 0);
                if (match(_A, _C, SA)) {
                    cout << "1\n";
                } else {
                    cout << "0\n";
                }
            }
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