#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[100005];
ll B[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N;
    while (cin >> N) {
        for (ll i = 0; i < (1LL << N); i++) {
            cin >> A[i];
        }

        memset(B, 0, sizeof(ll) * (1LL << N) + 5);
        for (ll i = 0; i < (1LL << N); i++) {
            for (ll j = 0; j < N; j++) {
                B[i] += A[i^(1LL << j)];
            }
        }

        ll _max = LONG_LONG_MIN;
        for (ll i = 0; i < (1LL << N); i++) {
            for (ll j = 0; j < N; j++) {
                _max = max(_max, B[i]+B[i^(1LL << j)]);
            }
        }
        cout << _max << "\n";
    }
    
    return 0;
}