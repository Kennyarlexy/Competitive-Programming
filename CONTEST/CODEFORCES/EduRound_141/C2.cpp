#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[500005];
ll R[1005]; //rank
ll P[500005];
ll cnt[1005];

ll f(ll i, ll n) {
    ll sum = A[i];
    if (i+2 <= n) sum += P[i+2];
    return sum;
}

ll g(ll i, ll n) {
    ll sum = 2*A[i];
    if (i+3 <= n) sum += P[i+3];
    return sum;
}

ll getRank(ll i, ll n) {
    ll rank;
    if (i == 1) rank = 1;
    else if (i <= n) {
        rank = R[A[i]];
        if (i < n && A[i] != A[i+1]) rank += cnt[A[i]] - 1;
    } else rank = n + 1;
    return rank;
}

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll n, m; cin >> n >> m;
        memset(cnt, 0, sizeof(cnt));
        for (ll i = 1; i <= n; i++) {
            cin >> A[i];
            cnt[A[i]]++;
        }

        sort(A+1, A+n+1, greater<ll>());
        R[A[1]] = 1;
        for (ll i = 2; i <= n; i++) {
            if (A[i] == A[i-1]) R[A[i]] = R[A[i-1]];
            else R[A[i]] = i;
        }

        for (ll i = n; i >= 1; i--) {
            P[i] = A[i];
            if (i < n) P[i] += P[i+1];
        }

        ll i = n+1;
        while (i-1 >= 1 && m >= P[i-1]) i--;
        ll R1 = getRank(i, n);

        i = n+1;
        ll step = n/2;
        while (step >= 1) {
            while (i-step >= 1 && m >= f(i-step, n)) i -= step;
            step /= 2;
        }

        ll R2 = getRank(i, n);

        i = n+1;
        step = n/2;
        while (step >= 1) {
            while (i-step >= 1 && m >= g(i-step, n)) i -= step;
            step /= 2;
        }
        ll R3 = getRank(i, n);

        cout << min(R1, min(R2, R3)) << "\n";
    }

    return 0;
}