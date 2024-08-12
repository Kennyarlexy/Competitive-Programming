#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[100005];

int main() {
    fast_io();
    //use ll when possible!
    ll N, D; cin >> N >> D;
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }    

    sort(A, A + N, greater<int>());
    ll r = N-1;
    ll cnt = 0;
    for (ll l = 0; l <= r; l++) {
        ll add_member = (D + A[l]) / A[l] - 1;
        if (l + add_member > r) break;
        cnt++;
        r -= add_member;
    }

    cout << cnt << "\n";

    return 0;
}