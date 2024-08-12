#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll f(ll n) {
    if (n < 10) return n;
    ll sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return f(sum);
}

int main() {
    fast_io();
    //use ll when possible!
    ll n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        cout << f(n) << "\n";
    }

    return 0;
}