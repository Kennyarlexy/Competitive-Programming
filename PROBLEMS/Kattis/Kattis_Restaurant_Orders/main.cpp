#include <bits/stdc++.h>
#define ll long long
using namespace std;

int dp[105][30005];
int A[105];
int n;

int dpf(int i, int x) {
    if (i > n || x < 0) return 0;
    if (x == 0) return 1;
    
    if (dp[i][x] != -1) return dp[i][x];

    int f = dpf(i, x-A[i]);
    int g = dpf(i+1, x);

    if (f == -2 || g == -2 || (f && g)) 
        return dp[i][x] = -2;
    if (f == 0 && g == 0) 
        return dp[i][x] = 0;

    return dp[i][x] = 1;
}

void print_dp(int i, int x) {
    if (x == 0) return;
    
    int f = dpf(i, x-A[i]);
    int g = dpf(i+1, x);

    assert(f + g == 1);

    if (f == 0) {
        assert(g == 1);
        print_dp(i+1, x);
    } else {
        assert(f == 1);
        cout << i << " ";
        print_dp(i, x-A[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);    
    memset(dp, -1, sizeof(dp));
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    int Q; cin >> Q;
    for (int q = 1; q <= Q; q++) {
        int x; cin >> x;
        int f = dpf(1, x);
        if (f == 0) cout << "Impossible\n";
        else if (f == -2) cout << "Ambiguous\n";
        else {
            print_dp(1, x);
            cout << "\n";
        }
    }
    
    return 0;
}