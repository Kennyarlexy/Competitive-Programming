#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

bool A[5005];

int main() {
    fast_io();
    //use ll when possible!
    ll N; cin >> N;
    ll cnt = 0;
    for (ll i = 1; i <= N; i++) {
        ll a; cin >> a;
        if (a < 0 && !A[-a]) cnt++;
        else if (a > 0) A[a] = true;
    }
    cout << cnt << "\n";

    return 0;
}