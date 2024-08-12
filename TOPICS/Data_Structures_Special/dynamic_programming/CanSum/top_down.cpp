/* 
    try to make a sum equal to target using elements in N. all elements in N can be used multiple times

    Note:
    - It's better to use top-down DP for this kind of problem since we don't actually need to check all states
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll dp[1005]; //or char for better memory usage
ll N[15];
ll t, n;

bool f(ll target) {
    if (target < 0) return false;
    if (target == 0) return true;
    if (dp[target] != -1) return dp[target];

    for (ll i = 1; i <= n; i++) {
        ll rem = target - N[i];
        if (f(rem)) {
            dp[target] = true;
            return true;
        }
    }

    return false;
}

int main() {
    fast_io();
    //use ll when possible!
    memset(dp, -1, sizeof(dp));
    cin >> t >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> N[i];
    }

    bool possible = f(t);
    cout << (possible ? "YES" : "NO") << "\n";

    return 0;
}