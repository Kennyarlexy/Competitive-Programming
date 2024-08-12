#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll target, n; 
vector<ll> res[1005];
ll dp[1005];
ll A[55];

bool f(ll T) {
    if (T < 0 || dp[T] == -2) return false;
    if (T == 0 || dp[T] != -1) return true;
    
    for (ll i = 1; i <= n; i++) {
        ll rem = T - A[i];
        if (f(rem)) {
            res[T] = res[rem];
            res[T].push_back(A[i]);
            return dp[T] = true;
        }
    }

    dp[T] = -2;
    return false;
}

int main() {
    fast_io();
    //use ll when possible!
    memset(dp, -1, sizeof(dp));
    cin >> target >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> A[i];
    }

    if (f(target)) {
        cout << "YES\n";
        for (auto& data : res[target]) {
            cout << data << " ";
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}