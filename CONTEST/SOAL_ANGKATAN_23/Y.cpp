#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll f(ll x1, ll y1, ll x2, ll y2) {
    if (x1 == x2 && y1 == y2) {
        return 0;
    } else if (x1 == x2) {
        return abs(y2-y1);
    } else if (y1 == y2) {
        return abs(x2-x1);
    } else {
        ll x = abs(x1-x2) + abs(y1-y2) + 2;
        return x;
    }
}

const ll Z = 1000000000000LL;

ll A[2][2] = {
    {Z, -Z},
    {Z, -Z}
};
ll B[2] = {2, 3};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;

    for (int i = 1; i <= N; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        ll x = f(x1, y1, x2, y2)*B[i%2];
        A[i%2][0] = min(A[i%2][0], x);
        A[i%2][1] = max(A[i%2][1], x);
    }

    ll ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ans = max(ans, abs(A[1][i] - A[0][j]));
        }
    }
    
    // ll ans = max(A[0][1] - A[1][0], A[1][1] - A[0][0]);
    cout << ans << "\n";

    
    return 0;
}

/*
2
0 0 0 1000000000
0 0 0 0
*/