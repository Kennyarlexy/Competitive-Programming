#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct State {
    ll delegates, vote_me, vote_him, vote_idk;
};

vector<State> A;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    ll X = 0, Y = 0, Z = 0;
    for (int i = 1; i <= n; i++) {
        ll delegates, vote_me, vote_him, vote_idk;
        cin >> delegates >> vote_me >> vote_him >> vote_idk;

        if (vote_me + vote_idk <= vote_him) Y += delegates;
        else if (vote_him + vote_idk < vote_me) X += delegates;
        else {
            A.emplace_back(delegates, vote_me, vote_him, vote_idk);    
            Z += delegates;
        } 
    }

    int m = A.size();
    vector<vector<ll>> dp(2, 
    vector<ll> (Z+1, -1));

    int now = 0, past = 1;
    dp[now][0] = 0;
    for (int i = 0; i < m; i++) {
        swap(now, past);
        for (int j = 0; j <= Z; j++) {
            dp[now][j] = dp[past][j];
            if (j - A[i].delegates >= 0 && dp[past][j - A[i].delegates] != -1) {
                ll N = (A[i].vote_him - A[i].vote_me + A[i].vote_idk) / 2 + 1; // cost
                dp[now][j] = (dp[now][j] == -1) ? dp[past][j - A[i].delegates] + N : min(dp[past][j - A[i].delegates] + N, dp[now][j]);
            }
        }
    }

    ll mn = LLONG_MAX;
    bool OK = false;
    for (int i = 0; i <= Z; i++) {
        if (dp[now][i] != -1 && X + i > Y + (Z-i)) {
            mn = min(mn, dp[now][i]);
            OK = true;
        }
    }

    if (OK) cout << mn << "\n";
    else cout << "impossible\n";
    
    return 0;
}