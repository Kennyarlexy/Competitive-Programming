#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[100005];

int main() {
    fast_io();
    //use ll when possible!
    ll L;
    while (cin >> L && L) {
        string s; cin >> s;
        for (ll i = 1; i < L; i++) {
            string d; cin >> d;
            if (d == "+y") A[i] = 1;
            else if (d == "-y") A[i] = 2;
            else if (d == "+z") A[i] = 3;
            else A[i] = 4;
        }

        ll cur = 1;
        for (ll i = L-1; i >= 1; i--) {
            if (cur == 1) {
                if (A[i] == 1) cur = 2;
                else if (A[i] == 2) cur = 4;
                else if (A[i] == 3) cur = 5;
                else cur = 6;
            } else if (cur == 2) {
                if (A[i] == 1) cur = 3;
                else if (A[i] == 2) cur = 1;
                else if (A[i] == 3) cur = 5;
                else cur = 6;
            }
        }
    }

    return 0;
}