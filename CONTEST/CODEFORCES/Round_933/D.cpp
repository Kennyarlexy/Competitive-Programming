#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
#define Point pair<ll, ll>
using namespace std;

ll f(ll a, ll r, ll n) {
    a += r;
    if (a < 1) a += n;
    else if (a > n) a -= n;
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m, x; cin >> n >> m >> x;
        set<ll> A, B;
        set<ll> *X = &A, *Y = &B;

        X->insert(x);
        for (int i = 1; i <= m; i++) {
            int r; char c;
            cin >> r >> c;
            if (c == '0') {
                for (auto a : *X) Y->insert(f(a, r, n));
            } else if (c == '1') {
                for (auto a : *X) Y->insert(f(a, -r, n));
            } else {
                for (auto a : *X) {
                    Y->insert(f(a, r, n));
                    Y->insert(f(a, -r, n));
                }
            }

            swap(X, Y);
            Y->clear();
        }

        cout << X->size() << "\n";
        for (auto a : *X) {
            cout << a << " ";
        }
        cout << "\n";
    }
    
    return 0;
}