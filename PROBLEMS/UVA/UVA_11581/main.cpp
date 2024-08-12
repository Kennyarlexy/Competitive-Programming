#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[5][5];
ll B[5][5];
ll dr[] = {1, 0, -1, 0};
ll dc[] = {0, -1, 0, 1};

bool OK() {
    for (ll r = 1; r <= 3; r++) {
        for (ll c = 1; c <= 3; c++) {
            if (A[r][c] != 0) return true;
        }
    }
    return false;
}

bool f(ll i) {
    if (i == 0) return OK();
    
    for (ll r = 1; r <= 3; r++) {
        for (ll c = 1; c <= 3; c++) {
            B[r][c] = 0;
            for (ll d = 0; d < 4; d++) {
                ll nr = r + dr[d];
                ll nc = c + dc[d];
                if (nr < 1 || nr > 3) continue;
                if (nc < 1 || nc > 3) continue;
                B[r][c] += A[nr][nc];
            }

            B[r][c] %= 2;
        }
    }

    for (ll r = 1; r <= 3; r++) {
        for (ll c = 1; c <= 3; c++) {
            A[r][c] = B[r][c];
        }
    }

    return OK();
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        for (ll r = 1; r <= 3; r++) {
            for (ll c = 1; c <= 3; c++) {
                char a; cin >> a;
                A[r][c] = a-'0';
            }
        }

        ll i = -1;
        while (f(i+1)) i++;
        cout << i << "\n";
    }
    
    return 0;
}