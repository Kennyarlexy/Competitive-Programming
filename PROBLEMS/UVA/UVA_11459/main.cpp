#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll G[105];
ll P[1000005]; //pos

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll a, b, c;
        cin >> a >> b >> c;
        fill(P, P + a + 5, 1);
        memset(G, -1, sizeof(G));

        for (ll i = 1; i <= b; i++) {
            ll from, to; cin >> from >> to;
            G[from] = to;
        }

        ll flag = false;
        for (ll i = 1; i <= c; i++) {
            ll roll; cin >> roll;
            if (flag) continue;
            ll player = i%a;
            P[player] += roll;
            if (G[P[player]] != -1) P[player] = G[P[player]];

            if (P[player] == 100) flag = true;
        }

        for (ll i = 1; i <= a; i++) {
            cout << "Position of player " << i << " is " << P[i%a] << ".\n"; 
        }
    }
    
    return 0;
}