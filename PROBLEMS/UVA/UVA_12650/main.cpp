#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool A[10010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, R;
    while (cin >> N >> R) {
        if (N != R) memset(A, 0, sizeof(ll)*N + 5);
        for (ll i = 1; i <= R; i++) {
            ll a; cin >> a;
            A[a] = true;
        }

        if (N == R) cout << "*\n";
        else {
            for (ll i = 1; i <= N; i++) {
                if (!A[i]) cout << i << " ";
            }
            cout << "\n";
        }
    }
    
    return 0;
}