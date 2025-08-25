#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, M; cin >> N >> M;
    
    if (M % N == 0) {
        ll shift = M / N;
        ll start = (N/2*2) * -1 + shift;
        if (N % 2 == 0) start++;

        cout << "YA\n";
        for (ll i = 1, x = start; i <= N; i++, x += 2) {
            cout << x << " \n"[i==N];
        }
    } else if (N % 2 == 0 && abs(M % N) == N/2) {
        M -= N/2;
        ll shift = M / N;
        ll start = -N/2 + 1 + shift;

        cout << "YA\n";
        for (ll i = 1, x = start; i <= N; i++, x++) {
            cout << x << " \n"[i==N];
        }
    } else {
        cout << "TIDAK\n";
    }
    
    return 0;
}