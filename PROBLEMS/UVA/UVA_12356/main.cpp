#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll L[100005];
ll R[100005];

int main() {
    fast_io();
    //use ll when possible!
    ll S, reports; 
    while (true) {
        cin >> S >> reports;
        if (S == 0 && reports == 0) break;
        for (ll i = 1; i <= S; i++) {
            R[i] = i+1;
        }

        for (ll i = 1; i <= S; i++) {
            L[i] = i-1;
        }

        for (ll i = 1; i <= reports; i++) {
            ll l, r; cin >> l >> r;
            if (L[l] > 0) {
                cout << L[l] << " ";
                R[L[l]] = R[r];
            }
            else cout << "* ";

            if (R[r] <= S) {
                cout << R[r] << "\n";
                L[R[r]] = L[l];
            }
            else cout << "*\n";
        }
        cout << "-\n";
    }    

    return 0;
}