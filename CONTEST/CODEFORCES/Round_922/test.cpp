#include <bits/stdc++.h>
#define ll unsigned long long
#define fi first 
#define se second
// #define LSOne(x) ((x) & (-x))
using namespace std;

ll diff(ll a, ll b) {
    return max(a, b) - min(a, b);
}

ll LSOne(ll y) {
    if (y == 0) return 0;
    ll x = (1ULL << __builtin_ctzll(y));
    return x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll test = (1LL << 63);
    cout << test << "\n";
    
    return 0;
}