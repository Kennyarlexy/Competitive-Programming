#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

ll A[100005];
ll sum(ll l, ll r) {
    ll X = A[r] - A[l-1];
    return X;
}

ll f(ll a, ll b, ll n) {
    ll X = n*(2*a + (n-1) * b) / 2;
    return X;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            A[i] += A[i-1];
        }

        int Q; cin >> Q;
        for (int q = 1; q <= Q; q++) {
            ll l, u; cin >> l >> u;
            ll r = l;
            for (ll step = (n-l)/2; step > 0; step /= 2) {
                while (r+step <= n && sum(l, r+step) <= u+1) {
                    r += step;
                }
            }

            if (A[r] - A[r-1] == 1 && sum(l, r) == u+1) {
                // cout << "A\n";
                r--;
            } else if (r+1 <= n && f(u, -1, sum(l, r+1)) > f(u, -1, sum(l, r))) {
                // cout << "B\n";
                r++;
            }
            cout << r << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
1
4
1 3 3 1
2
2 6
2 5

1
10
9 1 6 7 6 3 10 7 3 10
5
10 43
3 23
9 3
6 8
5 14


1
6
3 1 4 1 5 9
3
1 8
2 7
5 9

1
1
10
1
1 1
*/