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
        ll tea = (N+1)*T;
        ll exp = money;
        while (true) {
            ll price = tea + exp;
            price += (price + 9)/10;
            if (price <= money) break;
            exp--;
        }
        // [now/past][money][choosed_k]
        vector<vector<vector<ll>>> dp(2, vector<vector<ll>> (exp+1, vector<ll> (2*N+5, 0)));
        int now = 0, past = 1;
        for (int i = 1; i <= 2*K; i++) {
            swap(now, past);
            auto &dp_now = dp[now];
            auto &dp_past = dp[past];
            for (int j = 0; j <= exp; j++) {
                for (int k = 1; k <= 2*N+2; k++) {
                    dp_now[j][k] = dp_past[j][k];
                    if (j - A[i].fi >= 0) {
                        dp_now[j][k] = max(dp_now[j][k], dp_now[j-A[i].fi][k-1] + A[i].se);
                    }
                }
            }
        }

        ll mx = dp[now][exp][2*N+2];
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