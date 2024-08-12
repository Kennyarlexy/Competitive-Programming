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
    ll N; cin >> N;
    ll n = 0;
    for (ll i = 2; i*i <= N; i++) {
        if (N % (i*i) == 0) {
            n = i;
        }
    }

    if (n == 0) cout << 0 << "\n";
    else cout << n-1 << "\n";

    return 0;
}