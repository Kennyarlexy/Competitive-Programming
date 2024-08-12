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
        vector<vector<ll>> dp(m, vector<ll> (m, INF));
        dp[0][0] = 0;
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = dp[i-1][j];
                if (j > 0 && dp[i-1][j-1] + V[i] <= i - (j-1)) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + V[i]);
            }
        }

        ll x = m-1;
        while (dp[m-1][x] == INF) x--;
        ll ans = m - x;
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