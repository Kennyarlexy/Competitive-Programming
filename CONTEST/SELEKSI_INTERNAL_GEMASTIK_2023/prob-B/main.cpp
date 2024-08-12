#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (ll i = 1; i <= 1000000; i++) {
        for (ll j = 1; j*i <= 1000000; j++) {
            A[i*j]++;
        }
    }

    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll a; cin >> a;
        cout << A[a] << "\n";
    }
    
    return 0;
}