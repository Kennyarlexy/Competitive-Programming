#include <bits/stdc++.h>
#define ll long long

using namespace std;

char board[10][10];

void pawnW(ll sr, ll sc) {
    if (board[sr-1][sc-1] == ' ') board[sr-1][sc-1] = '*';
    if (board[sr-1][sc+1] == ' ') board[sr-1][sc+1] = '*';
}

void pawnB(ll sr, ll sc) {
    if (board[sr+1][sc-1] == ' ') board[sr+1][sc-1] = '*';
    if (board[sr+1][sc+1] == ' ') board[sr+1][sc+1] = '*';
}

void knight(ll sr, ll sc) {
    ll dr[] = {1, 2, 2, 1, -1, -2, -2, -1};
    ll dc[] = {2, 1, -1, -2, -2, -1, 1, 2};
    for (ll i = 0; i < 8; i++) {
        ll nr = sr + dr[i];
        ll nc = sc + dc[i];
        if (nr < 1 || nr > 8) continue;
        if (nc < 1 || nc > 8) continue;
        if (board[nr][nc] == ' ') board[nr][nc] = '*';
    }
}

void bishop(ll sr, ll sc) {
    ll dr[] = {1, 1, -1, -1};
    ll dc[] = {1, -1, -1, 1};
    for (ll i = 0; i < 4; i++) {
        ll cr = sr, cc = sc;
        while (true) {
            cr += dr[i];
            cc += dc[i];
            if (cr < 0 || cr > 8) break;
            if (cc < 0 || cc > 8) break;

            if (board[cr][cc] == ' ') board[cr][cc] = '*';
            else if (board[cr][cc] != '*') break;
        }
    }
}

void rook(ll sr, ll sc) {
    ll dr[] = {1, 0, -1, 0};
    ll dc[] = {0, -1, 0, 1};
    for (ll i = 0; i < 4; i++) {
        ll cr = sr, cc = sc;
        while (true) {
            cr += dr[i];
            cc += dc[i];
            if (cr < 0 || cr > 8) break;
            if (cc < 0 || cc > 8) break;

            if (board[cr][cc] == ' ') board[cr][cc] = '*';
            else if (board[cr][cc] != '*') break;
        }
    }
}

void queen(ll sr, ll sc) {
    bishop(sr, sc);
    rook(sr, sc);
}

void king(ll sr, ll sc) {
    ll dr[] = {1, 1, 1, 0, -1, -1, -1, 0};
    ll dc[] = {1, 0, -1, -1, -1, 0, 1, 1};
    for (ll i = 0; i < 8; i++) {
        ll nr = sr + dr[i];
        ll nc = sc + dc[i];
        if (board[nr][nc] == ' ') board[nr][nc] = '*';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string FEN;
    while (cin >> FEN) {
        fill((char*) board, (char*) board + 100, ' ');
        ll r = 1, c = 1;
        for (auto& ch : FEN) {
            if (ch >= '1' && ch <= '8') c += (ch - '0');
            else if (ch == '/') {
                r++;
                c = 1;
            } else {
                board[r][c++] = ch;
            }
        }


        for (ll cr = 1; cr <= 8; cr++) {
            for (ll cc = 1; cc <= 8; cc++) {
                if (board[cr][cc] == 'p') pawnB(cr, cc);
                else if (board[cr][cc] == 'P') pawnW(cr, cc);
                else if (tolower(board[cr][cc]) == 'r') rook(cr, cc);
                else if (tolower(board[cr][cc]) == 'n') knight(cr, cc);
                else if (tolower(board[cr][cc]) == 'b') bishop(cr, cc);
                else if (tolower(board[cr][cc]) == 'q') queen(cr, cc);
                else if (tolower(board[cr][cc]) == 'k') king(cr, cc);
            }
        }

        // for (ll rr = 1; rr <= 8; rr++) {
        //     for (ll cc = 1; cc <= 8; cc++) {
        //         cout << board[rr][cc] << " ";
        //     }
        //     cout << "\n";
        // }
        ll cnt = 0;
        for (ll cr = 1; cr <= 8; cr++) {
            for (ll cc = 1; cc <= 8; cc++) {
                if (board[cr][cc] == ' ') cnt++;
            }
        }
        cout << cnt << "\n";
    }
    
    return 0;
}

/*
4r3/8/8/4p2r/8/8/8/8
*/