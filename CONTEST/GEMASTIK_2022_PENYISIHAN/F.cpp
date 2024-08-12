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
    ll N, K, M; cin >> N >> K >> M;
    if ((K%2 * M%2)%2 == 0) {
        cout << "Kedua\n";
    } else {
        cout << "Pertama\n";
    }


    return 0;
}