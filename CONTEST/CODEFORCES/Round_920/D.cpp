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
        for (ll i = 1; i <= n; i++) {
            cin >> A[i];
        }

        multiset<ll> S;
        for (ll i = 1; i <= m; i++) {
            cin >> B[i];
            S.insert(B[i]);
        }

        sort(A+1, A+n+1);

        ll ans = 0;
        for (ll i = 1; i <= n; i++) {
            ll mn = *S.begin();
            ll mx = *S.rbegin();
            if (abs(mn-A[i]) > abs(mx-A[i])) {
                S.erase(S.find(mn));
                ans += abs(mn-A[i]);
            } else {
                S.erase(S.find(mx));
                ans += abs(mx-A[i]);
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}