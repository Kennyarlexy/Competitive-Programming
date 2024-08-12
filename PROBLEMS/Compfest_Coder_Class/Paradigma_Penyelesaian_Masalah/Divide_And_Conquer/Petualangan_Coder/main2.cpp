#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    ll X = 1, Y = 2;
    for (int i = 0; i <= 30; i++) {
        if (n & (1 << i)) (X *= Y) %= MOD;
        (Y *= Y) %= MOD;
    }

    cout << X - 1 << "\n";
    
    return 0;
}