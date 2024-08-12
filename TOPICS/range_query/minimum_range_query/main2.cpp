#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int A[32][1005];
ll pow2(ll k) {
    // return 2^k;
    return (1 << k);
}

int main() {
    fast_io();
    //use ll when possible!
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[0][i];
    }

    
    for (int j = 1; pow2(j) <= n; j++) {
        ll y = pow2(j);
        ll x = pow2(j-1);
        for (int i = 1; i + y-1 <= n; i++) {
            A[j][i] = min(A[j-1][i], A[j-1][i+x]);
        }
    }

    int Q; cin >> Q;
    for (int q = 1; q <= Q; q++)  {
        int l, r; cin >> l >> r;
        int len = r-l+1;
        int zeros = __builtin_clz(len);
        int k = 32 - zeros - 1;
        int x = pow2(k);

        int ans = min(A[k][l], A[k][r-x+1]); //O(1)
        cout << ans << "\n";
    }

    return 0;
}

/*
10
1 4 2 5 10 3 5 6 4 9
5
1 5
2 6
3 7
2 9
1 10
*/