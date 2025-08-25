#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        map<ll, ll> MP;
        ll a = LLONG_MAX, b = LLONG_MAX, c = LLONG_MIN, d = LLONG_MIN;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            MP[A[i]]++;
            if (MP[A[i]] == 2) {
                cnt++;
                b = min(b, A[i]);
                if (b < a) swap(a, b);

                c = max(c, A[i]);
                if (c > d) swap(c, d);
                MP[A[i]] -= 2;
            }

        }
        if (cnt < 4) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << b << " " << c << " ";
            cout << b << " " << a << " ";
            cout << d << " " << c << " ";
            cout << d << " " << a << "\n";
        }
    }
    
    return 0;
}