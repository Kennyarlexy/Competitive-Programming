#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        A[u]++;
        A[v]++;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] < n-1) ans++;
    }
    cout << ans << "\n";
    
    return 0;
}