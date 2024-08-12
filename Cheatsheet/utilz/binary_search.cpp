#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll f(ll x) {

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, x, y;

    // here
    for (ll step = n; step > 0; step /= 2) {
        // beware of writing f(x) instead of f(x + step) inside while loop
        while (x + step <= n && f(x + step) <= y) x += step;
    }

    
    return 0;
}