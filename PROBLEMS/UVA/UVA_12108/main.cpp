#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[15], B[15], C[15], L[15];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    ll T = 0;
    while (true) {
        cin >> n;
        if (n == 0) break;
        for (ll i = 1; i <= n; i++) {
            cin >> A[i] >> B[i] >> C[i];
            L[i] = A[i] + B[i];
        }

        ll res = -1;
        for (ll t = 1; t <= 100000; t++) {
            ll awake = 0, sleep = 0;
            for (ll i = 1; i <= n; i++) {
                if (C[i] <= A[i]) awake++;
                else sleep++;
            }

            if (awake == n) {
                res = t;
                break;
            }

            for (ll i = 1; i <= n; i++) {
                C[i]++;
                if (C[i] > L[i]) C[i] = 1;
                else if (C[i] == A[i] + 1 && sleep <= awake) C[i] = 1;
            }
        }

        cout << "Case " << ++T << ": " << res << "\n";
    }

    return 0;
}

/*
3
2 4 1
1 5 2
1 4 3
3
1 2 1
1 2 2
1 2 3
0
*/