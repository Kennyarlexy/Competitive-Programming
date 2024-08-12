#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[100005];
const int ROCK = 0, PAPER = 1, SCISSOR = 2;
int dp[100002][22][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("hps.in", "r", stdin);
    // freopen("hps.out", "w", stdout);
    
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        char ch; cin >> ch;
        if (ch == 'H') A[i] = ROCK;
        else if (ch == 'P') A[i] = PAPER;
        else A[i] = SCISSOR;
    }

    dp[1][0][ROCK] = (A[1] == SCISSOR);
    dp[1][0][PAPER] = (A[1] == ROCK);
    dp[1][0][SCISSOR] = (A[1] == PAPER);

    for (int i = 2; i <= n; i++) {
        dp[i][0][ROCK] = dp[i-1][0][ROCK] + (A[i] == SCISSOR);
        dp[i][0][PAPER] = dp[i-1][0][PAPER] + (A[i] == ROCK);
        dp[i][0][SCISSOR] = dp[i-1][0][SCISSOR] + (A[i] == PAPER);

        for (int j = 1; j <= min(i-1, k); j++) {
            dp[i][j][ROCK] = max(dp[i-1][j][ROCK], max(dp[i-1][j-1][SCISSOR], dp[i-1][j-1][PAPER])) + (A[i] == SCISSOR);
            dp[i][j][PAPER] = max(dp[i-1][j][PAPER], max(dp[i-1][j-1][ROCK], dp[i-1][j-1][SCISSOR])) + (A[i] == ROCK);
            dp[i][j][SCISSOR] = max(dp[i-1][j][SCISSOR], max(dp[i-1][j-1][ROCK], dp[i-1][j-1][PAPER])) + (A[i] == PAPER);
        }
    }

    int ans = 0;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < 3; j++) {
            ans = max(ans, dp[n][i][j]);
        }
    }

    cout << ans << "\n";
    
    return 0;
}


/*
10 20
H P P H H P P P P P
*/