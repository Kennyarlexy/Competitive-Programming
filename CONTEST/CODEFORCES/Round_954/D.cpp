#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second 
using namespace std;

pair<ll, ll> dp[25][2][2]; // [index][0 (add) | 1 (mul)][0 (not_skipped | 1 (skipped)]
ll A[25];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        string s; cin >> s;
        for (int i = 0; i < n; i++) {
            A[i] = s[i] - '0';
        }
        
        dp[0][0][0] = {A[0], 0};
        dp[0][1][0] = {0, A[0]};
        for (int i = 1; i < n; i++) {
            auto &S1 = dp[i][0][0];
            
            auto &P1 = dp[i-1][0][0];
            auto &P2 = dp[i-1][1][0];
            if (P1.fi < P2.fi + P2.se) S1 = {P1.fi + A[i], 0};
            else S1 = {P2.fi + P2.se + A[i], 0};
            
            if (P1.)
        }
    }
    
    return 0;
}