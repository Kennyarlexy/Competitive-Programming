#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

const ll MOD = 1e9 + 7;

ll modexp(ll X, ll n) {
    if (n <= 0) return 1;
    if (n==1) return X%MOD; 
    ll Y = modexp(X, n/2);
    ll Z = Y*Y % MOD;
    if (n % 2 == 1) Z = Z*X % MOD;

    return Z;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    return 0;
}