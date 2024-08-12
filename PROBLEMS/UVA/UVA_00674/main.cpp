#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[] = {50, 25, 10, 5, 1};
ll dp[5][8000];

ll dpf(int i, int x) {
    if (i == 5 || x < 0) return 0;
    if (x == 0) return 1;
    
    if (dp[i][x] != -1) return dp[i][x];

    return dp[i][x] = dpf(i, x-A[i]) + dpf(i+1, x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    int n;
    while (cin >> n) {
        ll ans = dpf(0, n);
        cout << ans << "\n";
    }
    
    return 0;
}