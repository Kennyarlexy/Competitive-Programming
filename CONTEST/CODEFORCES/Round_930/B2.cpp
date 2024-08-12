#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

void poly_hash(string &s, ll n, ll A, ll B, vector<ll> &H) {
    H[0] = s[0];
    for (int i = 1; i < n; i++) {
        H[i] = (H[i-1]*A + s[i]) % B;
    }
}

ll hash_val(ll l, ll r, ll B, vector<ll> &H, vector<ll> &X) {
    ll h = H[r];
    if (l > 0) h = (h - H[l-1]*X[r-(l-1)]) % B;
    if (h < 0) { // beware of min modulo
        h += B;
    }
    return h;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll n; cin >> n;
        string x, y; cin >> x >> y;

        ll j = n-1;
        for (int i = 0; i < n-1; i++) {
            if (x[i+1] == '1' && y[i] == '0') {
                j = i;
                break;
            }
        }

        string z = x.substr(0, j+1) + y.substr(j);
        
        vector<ll> H1(n+5), H2(n+5), H3(n+5), X(n+5);
        ll A = 957175135;
        ll B = 996362714;
        poly_hash(x, n, A, B, H1);
        poly_hash(y, n, A, B, H2);
        poly_hash(z, n+1, A, B, H3);
        X[0] = 1;
        for (int i = 1; i <= n; i++) {
            X[i] = X[i-1]*A % B;
        }

        // for (int i = 0; i < n; i++) cout << H1[i] << " \n"[i==n-1];

        ll h_min = H3[n];
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            ll h = H1[i]*X[n-i] % B;
            h = (h + hash_val(i, n-1, B, H2, X)) % B;
            if (h == h_min) cnt++;
        }
        cout << z << "\n";
        cout << cnt << "\n";
    }
    
    return 0;
}