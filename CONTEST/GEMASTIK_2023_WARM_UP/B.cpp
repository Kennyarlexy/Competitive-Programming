#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void multiply(ll F[2][2], ll M[2][2]);
void power(ll F[2][2], ll n);

ll mod = 1e9+7;
ll fib(ll n){
    ll F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0) return 0;
    power(F, n - 1);
    return F[0][0];
}

void power(ll F[2][2], ll n){
    if(n == 0 || n == 1) return;
    ll M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2); multiply(F, F);
    if (n % 2 != 0) multiply(F, M);
}

void multiply(ll F[2][2], ll M[2][2]){
    ll x = ((F[0][0] % mod * M[0][0] % mod) + (F[0][1] * M[1][0] % mod)) % mod;
    ll y = ((F[0][0] % mod * M[0][1] % mod) + (F[0][1] * M[1][1] % mod)) % mod;
    ll z = ((F[1][0] % mod * M[0][0] % mod) + (F[1][1] * M[1][0] % mod)) % mod;
    ll w = ((F[1][0] % mod * M[0][1] % mod) + (F[1][1] % mod * M[1][1] % mod)) % mod;

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
} // above code is a part of fast_fibo

int main() {
    fast_io();
    //use ll when possible!
    ll N; cin >> N;
    if (N <= 2) cout << N*N << "\n";
    else {
        ll X = (fib(N) + fib(N-1)) % mod;
        cout << X*X%mod << "\n";
    }

    return 0;
}