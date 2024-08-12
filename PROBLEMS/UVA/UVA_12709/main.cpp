#include <bits/stdc++.h>
#define ll long long
using namespace std;

pair<ll, ll> A[105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N; 
    while (true) {
        cin >> N;
        if (N == 0) break;
        for (ll i = 1; i <= N; i++) {
            ll L, W, H; cin >> L >> W >> H;
            A[i] = {H, L*W*H};
        }

        sort(A+1, A+N+1, greater<pair<ll, ll>> ());
        cout << A[1].second << "\n";
    }
    
    return 0;
}