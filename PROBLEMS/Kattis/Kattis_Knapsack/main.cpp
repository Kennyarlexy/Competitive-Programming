#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second 
using namespace std;

pair<int, int> A[2005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int C, n;
    while (cin >> C >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> A[i].fi >> A[i].se;
        }

        vector<vector<tuple<int, int, int>>> dp(n+1,
        vector<tuple<int, int, int>> (C+1, {0, -1, -1}));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= C; j++) {
                dp[i][j] = dp[i-1][j];
                if (j - A[i].se >= 0) {
                    auto [val, u, v] = dp[i-1][j-A[i].se];
                    if (val + A[i].fi > get<0>(dp[i][j])) {
                        dp[i][j] = {val + A[i].fi, v, i};
                    }
                }
            }
        }
        
        vector<int> ans;
        int w = C;
        auto [_, u, v] = dp[n][w];
        while (v != -1) {
            ans.push_back(v);
            if (u == -1) break;
            
            w -= A[v].se;
            tie(_, u, v) = dp[u][w];
        }

        cout << ans.size() << "\n";
        for (auto an : ans) cout << an-1 << " ";
        cout << "\n";
    }
    
    return 0;
}