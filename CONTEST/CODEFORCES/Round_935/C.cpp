#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second 
using namespace std;

char A[300005];
ll B[300005];

ll f(ll i, ll j) {
    ll x = B[j];
    if (i > 0) x -= B[i-1];
    return x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        B[1] = A[1] - '0';
        for (int i = 2; i <= n; i++) {
            B[i] = B[i-1] + A[i] - '0';
        }

        int j = -1;
        for (int i = n/2; i >= 0; i--) {
            ll L = i - f(0, i);
            ll R = f(i+1, n);

            if (L >= (i+1)/2 && R >= (n-i+1)/2) {
                j = i;
                break;
            }
        }

        int k = -1;
        for (int i = n/2+1; i <= n; i++) {
            ll L = i - f(0, i);
            ll R = f(i+1, n);

            // if (i == n) cout << L << " " << R << "\n";

            if (L >= (i+1)/2 && R >= (n-i+1)/2) {
                k = i;
                break;
            }
        }

        ll m = n/2;

        if (j == -1) {
            cout << k << "\n";
        } else if (k == -1) {
            cout << j << "\n";
        } else if (m - j <= k - m - (n % 2)) {
            cout << j << "\n";
        } else {
            cout << k << "\n";
        }

        // cout << f(0, 3) << "\n";
    }
    
    return 0;
}