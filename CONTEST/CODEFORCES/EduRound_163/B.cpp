#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll A[105];
pair<ll, ll> f(ll x) {
    return make_pair(x/10, x%10);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        ll a, b;
        tie(a, b) = f(A[1]);
        ll x = (a <= b && A[1] >= 10) ? b : A[1];

        bool g = true;
        for (int i = 2; i <= n; i++) {
            tie(a, b) = f(A[i]);
            if (A[i] < x) {
                g = false;
                break;
            } else {
                x = (a <= b && A[i] >= 10 && x <= a) ? b : A[i];
            }
        }
        cout << (g ? "YES": "NO") << "\n";
    }
    
    return 0;
}

/*
1
3
5 12 6
*/