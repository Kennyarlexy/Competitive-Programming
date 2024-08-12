#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    ll A, B, C; cin >> A >> B >> C;
    if (A + B == C || A - B == C || A * B == C || (B != 0 && (double) A / B == C) || B - A == C || (A != 0 && (double) B / A == C)) {
        cout << "YA\n"; 
    } else {
        cout << "TIDAK\n";
    }

    return 0;
}