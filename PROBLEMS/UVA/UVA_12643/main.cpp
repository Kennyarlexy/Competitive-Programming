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
    ll N, i, j;
    while (cin >> N >> i >> j) {
        ll round = 1;
        ll k = 2; //number of leaf nodes of this round, 2^round
        while ((i+k-1)/k != (j+k-1)/k) {
            round++;
            k *= 2;
        }
        cout << round << "\n";
    }

    return 0;
}