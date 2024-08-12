#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll cnt[1005];

ll dp[250005];
ll dpf(ll len) {
    if (len < 0) return 0;
    if (len == 0) return 1;
    if (dp[len] != -1) return dp[len];


    for (ll i = 1; i <= 500; i++) {
        if (cnt[i] == 0) continue;
        cnt[i]--;
        if (dpf(len-i)) {
            dp[len] = 1;
            return 1;
        }
        cnt[i]++;
    }

    dp[len] = 0;
    return dp[len];
}

int main() {
    fast_io();
    //use ll when possible!
    ll N; cin >> N;
    ll total = 0;
    for (ll i = 1; i <= N; i++) {
        ll L; cin >> L;
        if (L == 2) cnt[1] += 2;
        else cnt[L]++;
        total += L;
    }

    if (total % 2 == 1) {
        cout << "NO\n";
    } else {
        memset(dp, -1, sizeof(dp));
        bool OK1 = false;
        if (dpf(total/2) == 1) OK1 = true;

        memset(dp, -1, sizeof(dp));
        bool OK2 = false;
        if (dpf(total/2) == 1) OK2 = true;

        if (OK1 && OK2) cout << "YES\n";
        else cout << "NO\n";
    }
    // cout << "no error\n";

    return 0;
}