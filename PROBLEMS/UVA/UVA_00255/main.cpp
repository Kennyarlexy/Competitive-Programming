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
    ll k0, q0, q1;
    while (cin >> k0 >> q0 >> q1) {
        ll rk0 = k0 / 8;
        ll ck0 = k0 % 8;
        ll rq0 = q0 / 8;
        ll cq0 = q0 % 8;
        ll rq1 = q1 / 8;
        ll cq1 = q1 % 8;

        if (k0 == q0) {
            cout << "Illegal state\n";
        } 
        else if (abs(rq0-rq1) > abs(rq0-rk0) || abs(cq0-cq1) > abs(cq0-ck0) || (abs(rq0-rq1) != 0 && abs(cq0-cq1) != 0)) {
            cout << "Illegal move\n";
        } 
        else if (abs(rk0-rq1) == 1 && abs(ck0-cq1) == 1 && (k0 == 0 || k0 == 7 || k0 == 56 || k0 == 63)) {
            cout << "Stop\n";
        } 
        else if ((rk0 != 0 && q1 == k0-8) || (rk0 != 7 && q1 == k0+8) || (ck0 != 0 && q1 == k0-1) || (ck0 != 7 && q1 == k0+1)) {
            cout << "Move not allowed\n";
        } 
        else {
            cout << "Continue\n";
        }
    }

    return 0;
}