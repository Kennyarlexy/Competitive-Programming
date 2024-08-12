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
        ll i = 0;
        for (ll step = N/2; step >= 1; step/=2) {
            while (i+step < N && A[i+step] <= target) i+=step;
        }
        if (A[i] == target) cout << "ada\n";
        else cout << "tidak ada\n";
    }

    return 0;
}