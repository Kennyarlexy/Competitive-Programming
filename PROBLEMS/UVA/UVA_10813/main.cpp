#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll pos_r[105];
ll pos_c[105];
ll crossed[10][10];

bool verify() {
    for (ll r = 1; r <= 5; r++) {        
        bool win = true;
        for (ll c = 1; c <= 5; c++) {
            if (!crossed[r][c]) {
                win = false;
                break;
            }
        }
        if (win) return true;
    }

    for (ll c = 1; c <= 5; c++) {
        bool win = true;
        for (ll r = 1; r <= 5; r++) {
            if (!crossed[r][c]) {
                win = false;
                break;
            }
        }
        if (win) return true;
    }

    bool win = true;
    for (ll r = 1; r <= 5; r++) {
        if (!crossed[r][r]) {
            win = false;
            break;
        }
    }
    if (win) return true;

    win = true;
    for (ll r = 1; r <= 5; r++) {
        if (!crossed[r][6-r]) {
            win = false;
            break;
        }
    }
    if (win) return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        memset(pos_r, -1, sizeof(pos_r));
        memset(pos_c, -1, sizeof(pos_c));
        memset(crossed, 0, sizeof(crossed));
        crossed[3][3] = true;
        for (ll r = 1; r <= 5; r++) {
            for (ll c = 1; c <= 5; c++) {
                if (r == 3 && c == 3) continue;
                ll k; cin >> k;
                pos_r[k] = r;
                pos_c[k] = c;
            }
        }

        bool gameOver = false;
        ll n = 0;
        for (ll i = 1; i <= 75; i++) {
            ll k; cin >> k;
            if (pos_r[k] != -1) {
                crossed[pos_r[k]][pos_c[k]] = true;
                if (!gameOver && verify()) {
                    gameOver = true;
                    n = i;
                }
            }
        }

        cout << "BINGO after " << n << " numbers announced\n";
    }
    
    return 0;
}