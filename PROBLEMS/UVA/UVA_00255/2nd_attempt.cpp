#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll k, q0, q1;
    while (cin >> k >> q0 >> q1) {
        ll rk = k / 8, ck = k % 8;
        ll rq0 = q0 / 8, cq0 = q0 % 8;
        ll rq1 = q1 / 8, cq1 = q1 % 8;

        if (q0 == k) {
            cout << "Illegal state\n";
        } 
        else if (q1 == q0 || q1 == k || (rq1 != rq0 && cq1 != cq0) || (ck == cq1 && rk > min(rq0, rq1) && rk < max(rq0, rq1)) || (rk == rq1 && ck > min(cq0, cq1) && ck < max(cq0, cq1))) {
            cout << "Illegal move\n";
        }
        else if ((k == 0 && q1 == 9) || (k == 7 && q1 == 14) || (k == 56 && q1 == 49) || (k == 63 && q1 == 54)) {
            cout << "Stop\n";
        }
        else if ((rk == rq1 && abs(ck - cq1) == 1) || (ck == cq1 && abs(rk - rq1) == 1)) {
            cout << "Move not allowed\n";
        }
        else {
            cout << "Continue\n";
        }
    }
    
    return 0;
}