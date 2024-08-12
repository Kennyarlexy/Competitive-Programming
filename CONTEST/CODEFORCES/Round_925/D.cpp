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
        ll n, x, y; cin >> n >> x >> y;
        map<pair<ll, ll>, ll> MP;
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ll a; cin >> a;
            ll k1 = (x - (a % x))%x;
            ll k2 = a % y;
            ans += MP[{k1, k2}];

            MP[{a%x, a%y}]++;
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}