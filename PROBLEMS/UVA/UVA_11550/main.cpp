#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[15][100];
bool C[15][15]; //connected
vector<ll> V;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    V.reserve(10);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        memset(C, 0, sizeof(C));
        ll n, m; cin >> n >> m;
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= m; j++) {
                cin >> A[i][j];
            }
        }

        ll E = 0;
        bool OK = true;
        for (ll j = 1; j <= m; j++) {
            V.resize(0);
            for (ll i = 1; i <= n; i++) {
                if (A[i][j]) V.push_back(i);
            }
            
            if (V.size() == 2 && !C[V[0]][V[1]] && !C[V[1]][V[0]]) {
                E++;
                C[V[0]][V[1]] = C[V[1]][V[0]] = true;
            } else if (V.size() != 0) {
                OK = false;
                break;
            }
        }

        if (OK && E == m) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    
    return 0;
}