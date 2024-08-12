#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

ll A[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        ll cnt = 0;
        ll x = LLONG_MAX;
        ll y = LLONG_MIN;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            if (A[i] == 1) cnt++;
            if (A[i] % 2 == 0) x = min(x, A[i]);
            else y = max(y, A[i]);
        }

        if (cnt >= 2) cout << "NO\n";
        else if (cnt == 1) cout << "YES\n";
        else if (x < y) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}