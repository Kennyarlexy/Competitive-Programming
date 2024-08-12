#include <bits/stdc++.h>
#define ll long long
using namespace std;

// prepare array H
void poly_hash(string &s, ll n, ll A, ll B, vector<ll> &H) {
    H[0] = s[0];
    for (int i = 1; i < n; i++) {
        H[i] = (H[i-1]*A + s[i]) % B;
    }
}

// precompute A_pow first!
ll hash_val(ll l, ll r, ll B, vector<ll> &H, vector<ll> &A_pow) {
    ll h = H[r];
    if (l > 0) h = (h - H[l-1]*A_pow[r-(l-1)]) % B;
    if (h < 0) { // beware of min modulo
        h += B;
    }
    return h;
}