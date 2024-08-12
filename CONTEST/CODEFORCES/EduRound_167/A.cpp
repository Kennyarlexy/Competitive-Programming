#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        if (y >= -1) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}