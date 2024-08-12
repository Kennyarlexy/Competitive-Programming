#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[500005];
ll B[500005];

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll n, m; cin >> n >> m;
        for (ll i = 0; i < n; i++) {
            cin >> A[i];
            B[i] = A[i];
        }

        sort(B, B+n);
        ll i = 0;
        while (i < n && m >= B[i]) {
            m -= B[i];
            i++;
        }

        if (i == 0) {
            cout << n+1 << "\n";
        }
        else if (i == n) {
            cout << 1 << "\n";
        }
        // already won against i-th opponent, i.e. already included?
        // then i-th opponent won't get +1 score, we get the same rank as i-th opponent
        else if (A[i] <= B[i-1]) {
            cout << n-i << "\n";
        } 
        // ignore hardest opponent, won't give us worse ranking since it's not the i-th opponent
        // as long as we still win against i opponent
        else if (m + B[i-1] >= A[i]) {
            cout << n-i << "\n";
        }
        // failed
        else {
            cout << n-i+1 << "\n";
        }
    }

    return 0;
}