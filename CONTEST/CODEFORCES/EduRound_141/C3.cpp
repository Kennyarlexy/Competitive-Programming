#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[500005];
ll P[500005];
ll R[1005]; //rank

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

        for (ll i = n; i >= 1; i--) {
            P[i] = A[i];
            if (i < n) P[i] += P[i+1];
        }

        ll R1 = n+1;
        for (ll i = 1; i <= n; i++) {
            if (m >= P[i]) {
                if (i < n && A[i] == A[i+1]) R1 = R[A[i]];
                else R1 = i;
                break;
            }
        }

        ll R2 = n+1;
        for (ll i = 1; i <= n-1; i++) {
            if (A[i] == A[i+1]) continue;
            if (m >= P[i] - A[i+1]) {
                R2 = i;
                break;
            }
        }

        ll R3 = n+1;
        for (ll i = 1; i <= n-2; i++) {
            if (A[i] != A[i+1]) continue;
            if (m >= P[i] - A[i+1] - A[i+2]) {
                R3 = R[A[i]];
                break;
            }
        }

        cout << min(R1, min(R2, R3)) << "\n";
    }

    return 0;
}

/*
1
3 3
3 1 1

1
5 5
5 1 1 1 1
*/