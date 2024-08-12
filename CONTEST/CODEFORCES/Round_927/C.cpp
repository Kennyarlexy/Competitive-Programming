#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

ll A[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll n, m; cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        string s; cin >> s;
        ll l = 1, r = n;
        for (int i = 0; i < n-1; i++) {
            if (s[i] == 'L') l++;
            else r--;
        }

        ll X = A[l] % m;
        vector<ll> ans; ans.reserve(n+5);
        ans.push_back(X);
        for (int i = n-2; i >= 0; i--) {
            if (s[i] == 'R') {
                r++;
                X = X*A[r]%m;
            } else {
                l--;
                X = X*A[l]%m;
            }
            ans.push_back(X);
        }

        for (int i = n-1; i >= 0; i--) {
            cout << ans[i] << " \n"[i==0];
        }
    }
    
    return 0;
}