#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int G[3005];
int C[3005];
vector<pair<int, int>> adj[6005];
bool vis[3005];
int dp[3005][3005]; // dp[i][j] = jumlah gold max jika mulai dari i dan punya sisa coin j

pair<int, int> dfs(int S, int F, int coin) {
    if (vis[S]) return dp[S][coin];

    vis[S] = true;
    coin += C[S];

    if (S != F) { // main aman kalau misal F itu bukan paling ujung
        for (auto& v : adj[S]) {
            if (coin-v.se < 0) continue;
            dp[S][coin] = max(dp[S][coin], dfs(v.fi, F, coin-v.se));
        }
    }
    dp[S][coin] += G[S];
    for (int j = 1; j <= coin; j++) {
        dp[S][j] = dp[S][j-1];
    }

    return dp[S][coin];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, S, F; cin >> N >> S >> F;
    for (int i = 1; i <= N; i++) {
        cin >> G[i];
    }

    int K; cin >> K;
    for (int i = 1; i <= K; i++) {
        int u, v, m; cin >> u >> v >> m;
        adj[u].push_back({v, m});
    }

    int D; cin >> D;
    for (int i = 1; i <= D; i++) {
        int no; cin >> no;
        C[no] = 1;
    }

    int res = dfs(S, F, 0);

    if (vis[F]) {
        cout << res << "\n";
    } else {
        cout << "-1\n";
    }
    
    return 0;
}