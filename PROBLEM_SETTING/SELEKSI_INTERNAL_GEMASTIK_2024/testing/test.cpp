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
    int A = 1000;
    int B = (A | (1 << 30));
    cout << B << "\n";

    return 0;
}