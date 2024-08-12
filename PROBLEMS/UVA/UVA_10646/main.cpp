#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}


int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        vector<string> A, B;
        for (ll i = 1; i <= 27; i++) {
            string c; cin >> c;
            A.push_back(c);
        }

        for (ll i = 1; i <= 25; i++) {
            string c; cin >> c;
            B.push_back(c);
        }
        ll Y = 0;
        for (ll i = 1; i <= 3; i++) {
            ll X = (A.back()[0] >= '2' && A.back()[0] <= '9' ? A.back()[0] - '0' : 10);

            Y += X;
            A.pop_back();
            for (ll j = 1; j <= 10-X; j++) {
                A.pop_back();
            }
        }
        cout << "Case " << t << ": ";
        if (Y < A.size()) cout << A[Y-1] << "\n";
        else cout << B[Y-A.size()-1] << "\n";
    }

    return 0;
}