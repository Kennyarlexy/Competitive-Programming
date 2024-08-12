#include <bits/stdc++.h>
using namespace std;

int A[3005];
int dp[3005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    dp[1] = 100;
    for (int i = 2; i <= N; i++) {
        dp[i] = 100;
        for (int j = i-1; j >= 1; j--) {
            if (A[i] > A[j]) dp[i] = max(dp[i], dp[j] + 100);
        }
    }
    
    int res = 0;
    for (int i = 1; i <= N; i++) {
        res = max(dp[i], res);
    }
    cout << res << "\n";
    
    return 0;
}

// intended DP, O(n^2) or better
/*
7
4 5 2 6 7 2 4
*/ 