#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
// #define Point pair<ll, ll>
// #define x fi
// #define y se
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        string s, f; cin >> s >> f;

        ll x = 0, y = 0, z = 0;
        for (int i = 0; i < n; i++) {
            x += (s[i] == '1');
            y += (f[i] == '1');
            z += (s[i] != f[i]);
        }

        if (x > y) swap(x, y);
        ll k = y-x;
        ll ans = k + (z-k)/2;
        cout << ans << "\n";
    }
       
    return 0;
}