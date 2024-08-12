#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
using namespace std;
const ll MOD = 1e9 + 7;
ll dp[5005][2];
void solve(){
    ll n, m; cin >> n >> m;
    dp[0][0] = dp[1][0] = 1;
    dp[0][1] = dp[1][1] = 1;
 
    for(ll i = 2; i <= n; i++){
        if(i <= m){
            dp[i][0] = dp[i][1] = (2*dp[i-1][0]) % MOD;
        }else{
            dp[i][0] = (dp[i-1][0] + dp[i-1][1] - dp[i-m-1][1] + MOD) % MOD;
            dp[i][1] = (dp[i-1][0] + dp[i-1][1] - dp[i-m-1][0] + MOD) % MOD;
        }
    }
    cout << (dp[n][0] + dp[n][1]) % MOD;
}
main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int t = 1;
while(t--) solve();
}