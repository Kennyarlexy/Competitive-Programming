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
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll N; cin >> N;
        for (ll i = 1; i <= N; i++) {
            cin >> A[i];
        }

        ll j = 0;
        bool OK = true;
        for (ll i = 2; i <= N; i++) {
            if (A[i] < A[i-1]) {
                j = i;
                OK = false;
                break;
            }
        }

        if (OK) {
            cout << "YA\n";
        }
        else if (N == 2) {
            cout << "TIDAK\n";
        } 
        else {
            bool OK2 = true;
            for (ll i = j; i < N; i+=2) {
                if (A[i] > A[i+1]) {
                    OK2 = false;
                    break;
                }
            }
            if (OK2) {
                cout << "YA\n";
            } else {
                cout << "TIDAK\n";
            }
        }
    }

    return 0;
}