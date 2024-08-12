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
    ll N, Q; cin >> N >> Q;
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (ll q = 1; q <= Q; q++) {
        ll target; cin >> target;
        ll l = 0, r = N-1;
        while (l <= r) {
            ll m = (l+r) / 2;
            if (A[m] < target) l = m+1;
            else if (A[m] > target) r = m-1;
            else break;
        }

        if (A[(l+r)/2] == target) cout << "ada\n";
        else cout << "tidak ada\n";
    }

    return 0;
}