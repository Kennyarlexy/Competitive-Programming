#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[15][15];
ll B[15][15];

void trans(ll N) {
    for (ll r = 1; r <= N; r++) {
        for (ll c = 1; c <= N; c++) {
            B[r][c] = A[r][c];
        }
    }
    for (ll r = 1; r <= N; r++) {
        for (ll c = 1; c <= N; c++) {
            A[r][c] = B[c][r];
        }
    }
}

void print(ll N) {
    for (ll r = 1; r <= N; r++) {
        for (ll c = 1; c <= N; c++) {
            cout << A[r][c];
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll N; cin >> N;
        for (ll r = 1; r <= N; r++) {
            for (ll c = 1; c <= N; c++) {
                char a; cin >> a;
                A[r][c] = a-'0';
            }
        }

        ll M; cin >> M;
        for (ll i = 1; i <= M; i++) {
            string cmd; cin >> cmd;
            if (cmd == "row") {
                ll a, b; cin >> a >> b;
                for (ll c = 1; c <= N; c++) {
                    swap(A[a][c], A[b][c]);
                }
            } else if (cmd == "col") {
                ll a, b; cin >> a >> b;
                for (ll r = 1; r <= N; r++) {
                    swap(A[r][a], A[r][b]);
                }
            } else if (cmd == "inc") {
                for (ll r = 1; r <= N; r++) {
                    for (ll c = 1; c <= N; c++) {
                        A[r][c]++;
                        if (A[r][c] == 10) A[r][c] = 0;
                    }
                }
            } else if (cmd == "dec") {
                for (ll r = 1; r <= N; r++) {
                    for (ll c = 1; c <= N; c++) {
                        A[r][c]--;
                        if (A[r][c] == -1) A[r][c] = 9;
                    }
                }
            } else {
                trans(N);
            }
        }

        cout << "Case #" << t << "\n";
        print(N);
        cout << "\n";
    }
    
    return 0;
}