#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    //use ll when possible!
    ll N, M; cin >> N >> M;
    if (M == 1) {
        ll res = N-1;
        cout << res << "\n";
    } else {
        ll res = (M-1)*N;
        cout << res << "\n";
    }

    return 0;
}