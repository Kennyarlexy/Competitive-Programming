#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int G[3005];
vector<pair<int, int>> adj[3005];
int coin[3005];
int dp[3005][3005];

bool flag = false;

int dpf(int u, int x, int fin) {
    if (u == fin) return G[u];
    if (dp[u][x] != -1) return dp[u][x];

    dp[u][x] = -2;
    for (auto [v, monster] : adj[u]) {
        int y = x - monster + coin[u];
        if (y >= 0) dp[u][x] = max(dp[u][x], dpf(v, y, fin)); 
    }

    if (dp[u][x] != -2) dp[u][x] += G[u];
    return dp[u][x];
}

int main() {
    fast_io();
    //use ll when possible!
    memset(dp, -1, sizeof(dp));
    int N, S, F; cin >> N >> S >> F;
    for (int i = 1; i <= N; i++) {
        cin >> G[i];
    }

    int K; cin >> K;
    for (int i = 1; i <= K; i++) {
        int A, B, M; cin >> A >> B >> M;
        adj[A].push_back({B, M});
    }

    int C; cin >> C;
    for (int i = 1; i <= C; i++) {
        int x; cin >> x;
        coin[x] = 1;
    }

    int ans = dpf(S, 0, F);
    if (ans == -2) cout << "-1\n";
    else cout << ans << "\n";

    return 0;
}

/*
6 1 6
2 4 2 1 2 3
7
1 2 0
1 3 1
2 3 0
2 4 0
3 5 1
4 6 1
5 6 1
2
1 2

4 1 4
1 1 1 1
4
1 2 1
1 3 0
2 4 1
3 4 1
1
2
*/