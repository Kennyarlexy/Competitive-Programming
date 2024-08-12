#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m, k; cin >> n >> m >> k;
        int x = (n+m-1) / m;
        
        if (k >= n-x) cout << "NO\n";
        else cout << "YES\n";
    } 
    
    return 0;
}
