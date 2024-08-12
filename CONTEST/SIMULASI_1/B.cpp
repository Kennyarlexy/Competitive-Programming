#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[200005];

int main() {
    fast_io();
    //use ll when possible!
    ll n; cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A, A + n);
    for (ll i = 0; i < n; i++) {
        cout << A[i];
        if (i < n-1) cout << " ";
    }
    cout << "\n";

    return 0;
}