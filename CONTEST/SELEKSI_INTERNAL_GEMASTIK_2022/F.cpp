#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[200005];
ll pre[200005];

int main() {
    fast_io();
    //use ll when possible!
    ll N; cin >> N;
    for (ll i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    ll Q; cin >> Q;
    for (ll q = 1; q <= Q; q++) {
        ll L, R; cin >> L >> R;
        pre[L]++;
        pre[R+1]--;
    }

    for (ll i = 2; i <= N; i++) {
        pre[i] += pre[i-1];
    }

    for (ll i = 1; i <= N; i++) {
        if (pre[i] % 2 == 1) {
            swap(A[i], A[N-i+1]);
        }
    }

    for (ll i = 1; i <= N; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";

    return 0;
}