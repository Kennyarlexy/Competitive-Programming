#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll L[200005], R[200005];

bool intersect(ll a, ll b, ll c, ll d) {
    ll RRR = max(max(a, b), max(c, d));
    ll LLL = min(min(a, b), min(c, d));

    return RRR-LLL <= b-a + d-c;
}

bool f(int k, int n) {
    ll l = 0, r = 0;

    for (int i = 1; i <= n; i++) {
        l -= k;
        r += k;
        if (intersect(l, r, L[i], R[i])) {
            l = max(l, L[i]);
            r = min(r, R[i]);
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // cout << intersect(1, 2, 3, 3) << "\n"; return 0;

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> L[i] >> R[i];
        }

        if (f(0, n)) cout << "0\n";
        else {
            ll k = 1e9;

            for (ll step = k/2; step > 0; step /= 2) {
                while (k - step > 0 && f(k-step, n)) k -= step;
            }
            cout << k << "\n";
        }
    }
    
    return 0;
}