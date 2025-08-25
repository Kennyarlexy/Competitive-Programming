#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define fi first 
#define se second
using namespace std;

ll dp[105][105];

ll C(ll n, ll r) {
    if (n == r || r == 0) return 1;
    if (n < r) return 0;
    if (dp[n][r] != -1) return dp[n][r];

    return dp[n][r] = C(n-1, r-1) + C(n-1, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    ll N; cin >> N;

    ll cnt = 0;
    ll j = 64;
    ull X = 0;
    while (cnt < 30) {
        ll rem = 30 - cnt;
        ll i;
        for (i = j-1; i >= 0; i--) {
            if (C(i, rem) < N) {
                break;
            }
        }

        j = i;
        X |= (1ULL << j);
        N -= C(j, rem);
        cnt++;
    }

    cout << X << "\n";
    
    return 0;
}