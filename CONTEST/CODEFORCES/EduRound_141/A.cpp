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
        ll n; cin >> n;
        for (ll i = 0; i < n; i++) {
            cin >> A[i];
        }

        sort(A, A + n, greater<ll> ());
        ll l = 0;
        ll r = n-1;
        ll sum = 0;
        bool OK = true;
        while (l <= r) {
            if (A[l] == sum) {
                if (A[r] < sum) {
                    swap(A[l], A[r]);
                    r--;
                } else {
                    OK = false;
                    break;
                }
            }
            sum += A[l];
            l++;
        }

        // if (A[r] == sum) OK = false;
        if (OK) {
            cout << "YES\n";
            for (ll i = 0; i < n; i++) {
                cout << A[i] << " ";
            }
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}