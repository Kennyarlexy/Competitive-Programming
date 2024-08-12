#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[1005];

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll N; cin >> N;
        for (ll i = 1; i <= N; i++) {
            cin >> A[i];        
        }

        ll res = 1;
        for (ll i = 1; i <= N; i++) {
            res *= A[i];
        }

        res += (N-1);
        cout << 2022*res << "\n";
    }
    
    return 0;
}