#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll A[3505][3505];

int query(int l, int r, int u, int d) {
    return A[d][r] - A[d][l-1] - A[u-1][r] + A[u-1][l-1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char x; cin >> x;
            A[i+1000][j+1000] = x - '0';
        }
    }

// cout << "debug ----\n";
// for (int i = 1; i <= 10; i++) {
//     for (int j = 1; j <= 10; j++) {
//         cout << A[i+1000][j+1000];
//     }
//     cout << "\n";
// }
// cout << "debug ----\n";

    for (int i = 1; i <= 3000; i++) {
        for (int j = 1; j <= 3000; j++) {
            A[i][j] += A[i][j-1];
        }
    }

    for (int j = 1; j <= 3000; j++) {
        for (int i = 1; i <= 3000; i++) {
            A[i][j] += A[i-1][j];
        }
    }

// cout << "debug ----\n";
// cout << "prefix = " << query(1, 1+M+1000, 1, 1+N+1000) << "\n";
// cout << "debug ----\n";

    int Q; cin >> Q;
    for (int q = 1; q <= Q; q++) {
        ll R, C, K; cin >> R >> C >> K;
        R += 1000, C += 1000;

        ll start = query(C, C, R, R);
        K -= start;
        ll dist = 0;
        ll prev = start;
        ll time = 0;
        while (K > 0) {
            dist++;
            ll current = query(C-dist, C+dist, R-dist, R+dist);
            ll this_layer = current - prev;
            ll take = min(this_layer, K);
            time += take*dist*2;
            K -= take;
            prev = current;
        }

        cout << time << "\n";
    }
    
    return 0;
}