#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll dp[1005][1005];

ll C(ll n, ll r) {
    if (n == r || r == 0) return 1;
    if (n < r) return 0;

    return dp[n][r] = C(n-1, r-1) + C(n-1, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << C(1, 1) << "\n";
    cout << C(10, 5) << "\n";
    cout << C(10, 4) << "\n";
    cout << C(10, 6) << "\n";
    cout << C(5, 6) << "\n";
    
    return 0;
}