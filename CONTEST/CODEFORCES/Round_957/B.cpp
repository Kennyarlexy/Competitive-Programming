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
        ll n, k; cin >> n >> k;
        ll mx = LLONG_MIN;
        ll sum = 0;

        ll y = 0;
        for (int i = 1; i <= k; i++) {
            ll x; cin >> x;
            mx = max(mx, x);
            sum += x;
            y += (2*x-1);
        }

        y -= (2*mx-1);
        cout << y << "\n";
    }
    
    return 0;
}