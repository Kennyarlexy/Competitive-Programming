#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll target, n; 
ll dp[1005]; //remember previous
ll A[55];
ll cnt = 0;

bool f(ll T) {
    cnt++;
    if (T < 0 || dp[T] == -2) return false; //when dp[T] == -2, it means that the case is checked and we know that it's impossible
    if (T == 0 || dp[T] != -1) return true;

    for (ll i = 1; i <= n; i++) {
        ll rem = T - A[i];
        if (f(rem)) {
            dp[T] = rem;
            return true;
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
        ll cur = target;
        while (dp[cur] != -1) { //while previous of current exists
            cout << cur - dp[cur] << " ";
            cur = dp[cur]; //previous is the new current
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }

    cout << cnt << " checks done\n";

    return 0;
}