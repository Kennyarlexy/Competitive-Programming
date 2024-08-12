#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
// #define Point pair<ll, ll>
// #define x fi
// #define y se
using namespace std;

ll A[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll n, f, a, b; cin >> n >> f >> a >> b;
        for (ll i = 1; i <= n; i++) {
            cin >> A[i];
        }

        ll x = 0;
        for (ll i = 1; i <= n; i++) {
            x += min((A[i]-A[i-1]) * a, b);
        }
        
        if (x < f) cout << "YES\n";
        else cout << "NO\n";
    }
       
    return 0;
}