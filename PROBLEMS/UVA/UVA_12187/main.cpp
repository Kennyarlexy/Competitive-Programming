#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[105][105]; //after
ll B[105][105]; //before
ll dr[] = {1, 0, -1, 0};
ll dc[] = {0, -1, 0, 1};

void f(ll R, ll C, ll N) {
    for (ll r = 1; r <= R; r++) {
        for (ll c = 1; c <= C; c++) {
            B[r][c] = A[r][c];
        }
    }

    for (ll r = 1; r <= R; r++) {
        for (ll c = 1; c <= C; c++) {
            for (ll i = 0; i < 4; i++) {
                ll ar = r + dr[i];
                ll ac = c + dc[i];
                if (ar < 1 || ar > R) continue;
                if (ac < 1 || ac > C) continue;

                if ((B[r][c]+1)%N == B[ar][ac]) {
                    A[ar][ac] = B[r][c];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, R, C, K;
    while (true) {
        cin >> N >> R >> C >> K;
        if (N == 0 && R == 0 && C == 0 && K == 0) break;

        for (ll r = 1; r <= R; r++) {
            for (ll c = 1; c <= C; c++) {
                cin >> A[r][c];
            }
        }

        for (ll i = 1; i <= K; i++) {
            f(R, C, N);
        }

        for (ll r = 1; r <= R; r++) {
            for (ll c = 1; c <= C; c++) {
                cout << A[r][c] << " \n"[c==C];
            }
        }
    }
    
    return 0;
}

/*
3 3 3 1
0 0 1
0 1 1
0 2 2
0 0 0 0
*/