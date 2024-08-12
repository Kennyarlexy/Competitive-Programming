#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[500005];
ll P[500005];
ll R[1005];

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll n, m; cin >> n >> m;
        for (ll i = 1; i <= n; i++) {
            cin >> A[i];
        }

        sort(A+1, A+n+1, greater<ll>());
        R[A[1]] = 1;
        for (ll i = 2; i <= n; i++) {
            if (A[i] == A[i-1]) R[A[i]] = R[A[i-1]];
            else R[A[i]] = i;
        }

        reverse(A+1, A+n+1);
        // P[i] is the time needed to beat 1-th to i-th people from weaker to stronger
        P[1] = A[1];
        for (ll i = 2; i <= n; i++) {
            P[i] = A[i] + P[i-1];
        }

        ll x = 0; // beating x people max
        while (x+1 <= n && m >= P[x+1]) x++;

        if (x >= 2 && A[x] == A[x-1]) {
            cout << R[A[x]] << "\n";
        } else if (x >= 1 && x < n && m >= P[x+1] - A[x]) {
            cout << n-x << "\n";
        } else {
            cout << n-x+1 << "\n";
        }        
    }

    return 0;
}