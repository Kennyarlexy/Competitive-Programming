#include <bits/stdc++.h>
#define ll long long
using namespace std;

char A[105][105];
ll B[105][105];
ll dr[] = {1, 1, 1, 0, -1, -1, -1, 0};
ll dc[] = {1, 0, -1, -1, -1, 0, 1, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll R, C;
    bool OK = false;
    ll t = 0;
    while (cin >> R >> C) {
        if (R == 0 && C == 0) break;
        if (OK) cout << "\n";
        memset(B, 0, sizeof(B));
        for (ll r = 1; r <= R; r++) {
            for (ll c = 1; c <= C; c++) {
                cin >> A[r][c];
            }
        }

        for (ll r = 1; r <= R; r++) {
            for (ll c = 1; c <= C; c++) {
                if (A[r][c] == '*') {
                    for (ll i = 0; i < 8; i++) {
                        B[r+dr[i]][c+dc[i]]++;
                    }
                }
            }
        }

        cout << "Field #" << ++t << ":\n";
        for (ll r = 1; r <= R; r++) {
            for (ll c = 1; c <= C; c++) {
                if (A[r][c] == '*') cout << '*';
                else cout << B[r][c];
            }
            cout << "\n";
        }
        OK = true;
    }
    
    return 0;
}