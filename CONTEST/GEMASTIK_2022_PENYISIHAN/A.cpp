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
    ll A, B, C, D; cin >> A >> B >> C >> D;
    if (A*D == B*C) {
        cout << "sama\n";
    } else if (A*D < B*C) {
        cout << "lebih kecil\n";
    } else {
        cout << "lebih besar\n";
    }

    return 0;
}