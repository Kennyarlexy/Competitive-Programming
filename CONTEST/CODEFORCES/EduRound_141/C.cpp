#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[500005];
bool winVS[500005];
ll cnt[1005];

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll n, m; cin >> n >> m;

        memset(cnt, 0, sizeof(cnt));
        memset(winVS, 0, sizeof(ll)*n + 5);
        for (ll i = 1; i <= n; i++) {
            cin >> A[i];
            cnt[A[i]]++;
        }

        sort(A + 1, A + n + 1, greater<ll> ());
        ll myWin = 0;
        for (ll i = n; i >= 1; i--) {
            if (m < A[i]) break;
            myWin++;
            m -= A[i];
            winVS[i] = true;
        }


        ll i = 0;
        while (i <= n) {
            i++;
            if (A[i] != A[i-1]) {
                ll hisWin = n-i-(cnt[A[i]]-1);
                if (!winVS[i]) hisWin++;
                if (myWin >= hisWin) break;
            }
        }
        cout << i << "\n";
        // cout << myWin << "\n";
    }

    return 0;
}