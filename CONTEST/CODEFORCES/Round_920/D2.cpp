#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
// #define Point pair<ll, ll>
// #define x fi
// #define y se
using namespace std;
ll A[200005], B[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll n, m; cin >> n >> m;
        vector<ll> all;
        all.reserve(n+m);
        for (ll i = 1; i <= n; i++) {
            cin >> A[i];
            all.push_back(A[i]);
        }

        for (ll i = 1; i <= m; i++) {
            cin >> B[i];
            all.push_back(B[i]);
        }

        sort(all.begin(), all.end());
        sort(A+1, A+n+1);
        sort(B+1, B+m+1);
        ll median = all[(n+m+1)/2-1];
        ll i = 1;
        ll ans = 0;
        ll l = 1, r = m;

        while (A[i] < median) {
            ans += (B[r] - A[i]);
            r--;
            i++;
        }

        while (i <= n) {
            ll x = abs(A[i] - A[l]);
            ll y = abs(A[i] - B[r]);
            if (x < y) {
                ans += x;
                l++;
            } else {
                ans += y;
                r--;
            }
            i++;
        }
        cout << median << "\n";
        // cout << ans << "\n";
    }
    
    return 0;
}

/*
1
3 5
2 4 4
1 5 7 8 9
*/