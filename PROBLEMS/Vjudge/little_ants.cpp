#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 1; i <= N; i++) {
        int X; cin >> X;
        mn = min(mn, X);
        mx = max(mx, X);
    }

    int ans = (mn + mx) / 2;
    cout << ans << "\n";
    
    return 0;
}