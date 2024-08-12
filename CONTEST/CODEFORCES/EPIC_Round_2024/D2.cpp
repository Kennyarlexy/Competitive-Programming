#include <bits/stdc++.h>
#define ll long long
#define se second 
#define fi first
using namespace std;

ll A[10005];
const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        map<ll, ll> MP;
        for (ll i = 1; i <= n; i++) {
            cin >> A[i];
            MP[A[i]]++;
        }

        vector<ll> V;
        for (auto [k, freq] : MP) {
            V.push_back(freq);
        }

        ll m = V.size();
        vector<vector<pair<ll, ll>>> dp(m+5, vector<pair<ll, ll>> (m+5, {INF, -1}));
        
        dp[0][0] = {1, 1};
        for (ll i = 1; i < m; i++) {
            for (ll j = 0; j < i; j++) {
                // if (dp[i-1][j].se == 2) dp[i][j] = {dp[i-1][j].fi + 1, 1};
                // else {
                //     if (j >= V[i]) {
                //         if (dp[i-1][j-V[i]].fi < dp[i-1][j].fi + 1 && dp[i-1][j-V[i]].se == 1) {
                //             dp[i][j] = {dp[i-1][j-V[i]].fi, 2};
                //         } else {
                //             dp[i][j] = {dp[i-1][j].fi + 1, 1};
                //         }
                //     } else dp[i][0] = {i, 1};
                // }


                if (j >= V[i]) {
                    if (dp[i-1][j].se == 2 && dp[i-1][j-V[i]].se == 2) {
                        dp[i][j] = {min(dp[i-1][j].fi, dp[i-1][j-V[i]].fi) + 1, 1};
                    } else if (dp[i-1][j-V[i]].se == 1) {
                        if (dp[i-1][j-V[i]].fi < dp[i-1][j].fi + 1) dp[i][j] = {dp[i-1][j-V[i]].fi, 2};
                        else dp[i][j] = {dp[i-1][j].fi + 1, 1};
                    } else if (dp[i-1][j].se == 1) {
                        dp[i][j] = {dp[i-1][j].fi + 1, 1};
                    } else {
                        dp[i][j] = {min(dp[i-1][j].fi, dp[i-1][j-V[i]].fi), 2};
                    }
                } else dp[i][0] = {i, 1};
            }

            if (i >= V[i]){
                if (dp[i-1][i-V[i]].fi < i-1 && dp[i-1][i-V[i]].se == 1) dp[i][i] = {dp[i-1][i-V[i]].fi, 2};
                else dp[i][i] = {i-1, 2};
            } else dp[i][i] = {i, 2};
        }

        ll ans = LLONG_MAX;
        for (int i = 0; i < m; i++) {
            cout << dp[m-1][i].fi << " \n"[i == m-1];
            ans = min(ans, dp[m-1][i].fi);
        }

        cout << ans << "\n";
    }
    
    return 0;
}

/*
1
7
1 2 3 4 4 5 5

1
5
1 2 2 3 4

4
7
1 2 2 3 3 4 5
9
1 1 1 2 2 3 3 4 5

3
10
1 2 3 4 5 6 7 8 9 10
9 
1 2 3 4 5 6 7 8 9

1
11
1 2 3 4 5 6 6 6 7 8 9

2
15
1 2 2 3 3 3 4 4 4 4 5 5 5 5 5
14
1 2 2 3 3 3 4 4 4 4 5 5 5 5

1
9
4 3 5 6 6 6 4 8 5
3 4 4 5 5 6 6 6 8
*/