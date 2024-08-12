#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll A[1000005], B[1000005], C[1000005];
ll D[1000005];
ll dp[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n; i++) cin >> B[i];
    for (int i = 1; i <= m; i++) cin >> C[i];

    iota(D+1, D+n+1, 1);
    sort(D+1, D+n+1, [&] (int i, int j) {
        return A[i] < A[j];
    });
    
    vector<pair<int, int>> E;
    E.push_back({A[D[1]], A[D[1]] - B[D[1]]});
    for (int i = 2; i <= n; i++) {
        if (A[D[i]] - B[D[i]] < E.back().se) {
            if (E.back().fi == A[D[i]]) E.pop_back();
            E.push_back({A[D[i]], A[D[i]] - B[D[i]]});
        }
    }

    for (int i = 1; i <= 1000000; i++) {
        pair<int, int> temp = {i, 10000007};
        auto itr = upper_bound(E.begin(), E.end(), temp);
        if (itr == E.begin()) dp[i] = 0;
        else {
            itr--;
            dp[i] = dp[i - itr->se] + 2;
        }
    }

    ll X = 0;
    ll y = E.back().se;
    for (int i = 1; i <= m; i++) {
        if (C[i] > 1000000) {
            ll k = (C[i] - 1000000 + y - 1) / y;
            X += 2*k;
            C[i] -= y*k;
        }

        X += dp[C[i]];
    }

    cout << X << "\n";
    
    return 0;
}

/*
2 1
8 6
4 1
11

{6, 5}, {8, 4}

*/