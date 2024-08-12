#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

char A[1005];

ll f(int m) {
    map<ll, ll> MP;
    for (ll i = 2; i*i <= m; i++) {
        while (m % i == 0) {
            if (MP[i] == 0) MP[i] = 1;
            MP[i] *= i;
            m /= i;
        }
    }

    if (m > 1) MP[m] = m;

    ll phi = 1;
    for (auto [x, y] : MP) {
        phi *= y/x * (x-1);
    }

    return phi;
}

ll modexp(ll x, ll n, ll m) {
    if (n == 0) return 1;
    
    ll root = modexp(x, n/2, m);
    ll y = root*root % m;
    if (n % 2 == 1) y = y*x % m;
    
    return y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k = 0;
    A[0] = 'z';
    char ch = 'a';
    for (int i = 1; i <= 26; i++) {
        for (int j = 1; j <= i; j++) A[++k] = ch;
        ch++;
    }

    ll m = k;
    // cout << m << "\n";

    ll phi = f(m);
    // cout << phi << "\n";

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll i, j; cin >> i >> j;
        i %= phi;

        ll n = modexp(i, j, phi);
        ll z = modexp(2, n, m);

        cout << A[z] << "\n";
    }
    
    return 0;
}