#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll A[100005];
pair<ll, ll> dp[2][100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    dp[0][1] = {A[1], 0};
    dp[1][1] = {A[1] & A[2], A[1] & A[2]};
    
    for (int i = 2; i <= N; i++) {
        dp[0][i] = dp[1][i-1];
        dp[1][i] = {A[i-1] & A[i], dp[0][i-1].se + 
                   max((A[i]&A[i+1]) + (A[i]&A[i+1]&dp[0][i-1].fi), (dp[0][i-1].fi&A[i]) + (dp[0][i-1].fi&A[i]&A[i+1]))};
    }

    cout << dp[0][N].se << "\n";
    
    return 0;
}