#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[105];

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll N; cin >> N;
        ll x = 0;
        for (ll i = 1; i <= N; i++) {
            string s; cin >> s;
            if (s == "LEFT") {
                x--;
                A[i] = -1;
            } else if (s == "RIGHT") {
                x++;
                A[i] = 1;
            } else {
                string dump; ll k;
                cin >> dump >> k;
                x += A[k]; //k-th direction
                A[i] = A[k];
            }
        }
        cout << x << "\n";
    }

    return 0;
}