#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

ll adj[200005];
ll A[200005];
bool vis[200005];

ll f(ll s, ll k) {
    memset(vis, 0, sizeof(vis));
    ll mx = LLONG_MIN;
    ll sum = 0;
    while (!vis[s] && k > 0) {
        vis[s] = true;
        ll X = sum + A[s]*k;
        mx = max(mx, X);
        k--;
        sum += A[s];
        s = adj[s];
    }

    return mx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll n, k, x, y; cin >> n >> k >> x >> y;
        for (int i = 1; i <= n; i++) {
            cin >> adj[i];
        }

        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        ll X = f(x, k);
        ll Y = f(y, k);

        if (X > Y) cout << "Bodya\n";
        else if (X < Y) cout << "Sasha\n";
        else cout << "Draw\n";
    }
    
    return 0;
}