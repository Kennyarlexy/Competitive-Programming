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
        ll mn = LLONG_MAX;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            mn = min(A[i], mn);
        }

        ll cnt = 0;
        bool f = false;
        for (int i = 1; i <= n; i++) {
            if (A[i] == mn) cnt++;
            if (A[i] % mn != 0) f = true;
        }

        if (cnt < 2) cout << "YES\n";
        else {
            if (f) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    
    return 0;
}