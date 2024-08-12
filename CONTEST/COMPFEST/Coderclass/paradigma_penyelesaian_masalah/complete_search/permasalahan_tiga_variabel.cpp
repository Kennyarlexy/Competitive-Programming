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
    ll N; cin >> N;
    ll res = (N+1)*(2+N) / 2;
    cout << res << "\n";

    return 0;
}