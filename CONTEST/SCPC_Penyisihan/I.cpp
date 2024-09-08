#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

/*
    N * M * |1 - |(N-1)^K (M-1)^K| |
            |    |---------------| |
            |    |     (N*M)^K   | |
                 ^^^^^^^^^^^^^^^^^
                         A
                         

    P = N*M * (1 - (N-1)^K (M-1)^K)
    Q = (N*M)^K 
*/

const ll MOD = 998244353;

ll modexp(ll X, ll n) {
    if (n <= 0) return 1;
    if (n==1) return X%MOD; 
    ll Y = modexp(X, n/2);
    ll Z = Y*Y % MOD;
    if (n % 2 == 1) Z = Z*X % MOD;

    return Z;
}

unsigned long long gcdEx(ll a, ll b, ll *x, ll *y) {
     if (a == 0) {
          *x = 0, *y = 1;
          return b;
     }
     ll x1, y1;
     ll gcd = gcdEx(b%a, a, &x1, &y1);
     *x = y1 - (b/a) * x1;
     *y = x1;
     return gcd;
}

unsigned long long inverse(ll n) { // masukin ke sini 
    ll x, y;
    ll gce = gcdEx(n, MOD, &x, &y);
    if (gce != 1) {
        return -1;
    }
    return (x%MOD + MOD) % MOD;
}

/*
    N * M * |1 - |(N-1)^K (M-1)^K| |
            |    |---------------| |
            |    |     (N*M)^K   | |
                 ^^^^^^^^^^^^^^^^^
                         A
                         

    P = N*M * ((N*M)^K - (N-1)^K (M-1)^K)
    Q = (N*M)^K 
*/


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, M, K; cin >> N >> M >> K;
    ll A = modexp(N-1, K) * modexp(M-1, K) % MOD;
    // Compute (N*M)^K first!!!!
    ll bbb = N%MOD; // bbb = N*M
    bbb = (bbb*M)%MOD;

    ll nmk = modexp(bbb, K); /// (N*M)^K

    ll P = (nmk - A + MOD + MOD)%MOD;
    P = (P*bbb)%MOD;
    // P must be OK!!!!

    ll Q = modexp(bbb, K);
    cout << bbb << "^" << K << " = " << Q <<  '\n';
    // 
    Q = inverse(Q);

    // coba masukin TC 
    // 2 6 5
    
    cout << (P * Q) % MOD << '\n'; 
    return 0;
}