#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

pair<ll, ll> A[205];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, x, T, K;
    while (cin >> N >> x >> T >> K && (N || x || T || K)) {
        for (int i = 2; i <= 2*K; i += 2) {
            cin >> A[i].fi;
            A[i].se = 0;
            for (int j = 1; j <= N+1; j++) {
                ll a; cin >> a;
                A[i].se += a;
            }
            A[i-1] = A[i];
        }

        ll money = (N+1)*x;
        vector<vector<ll>> dp(2, vector<ll> (money+1));
        int now = 0, past = 1;

        for (int i = 1; i <= 2*K; i++) {
            swap(now, past);
            for (int j = 0; j <= money; j++) {
                dp[now][j] = dp[past][j];
                if (j - A[i].fi >= 0) dp[now][j] = max(dp[now][j], dp[past][j - A[i].fi] + A[i].se);
            }
        }

        ll mx = 0;
        for (int i = 0; i <= money; i++) {
            ll price = (N+1)*T + i;
            price += (price+9)/10;
            if (price > money) {
                cout << i-1 << "\n";
                break;
            }

            mx = max(dp[now][i], mx);
        }

        double ans = (double) mx / (N+1);
        cout << fixed << setprecision(2) << ans << "\n";
    }
    
    return 0;
}


/*
5 100 0 10
10 0 0 0 0 0 1
10 0 0 0 0 2 3
10 0 0 0 0 0 0
10 0 1 2 0 0 0
10 0 10 4 0 0 0
10 0 0 0 0 0 0
10 0 0 0 0 0 0
10 0 0 10 0 0 0
10 0 0 0 5 0 1
10 0 0 0 0 5 5
0 0 0 0

2 100 0 2
10 100 100 100
10 0 0 0
0 0 0 0
*/