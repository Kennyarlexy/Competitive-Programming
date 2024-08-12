//i think this results in TLE due to the very wide range of possible target (1 <= target <= 10^9) relative to the choices (1 <= choice <= 20), so the dp memo has a very little chance to be useful
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[25];
bool killed[25];
ll N, M; 
map<ll, bool> dp;

bool dpf(ll target) {
    if (target == 0) return true;
    auto itr = dp.find(target);
    if (target < 0) return false;
    if (itr != dp.end()) return itr->second;

    for (ll i = 1; i <= N; i++) {
        if (killed[i]) continue;
        ll rem = target - A[i];
        killed[i] = true;
        if (dpf(rem)) {
            dp[target] = true;
            return true;
        }
        killed[i] = false;
    }

    dp[target] = false;
    return false;
}

int main() {
    fast_io();
    //use ll when possible!
    cin >> N >> M;
    for (ll i = 1; i <= N; i++) {
        cin >> A[i];
    }    

    if (dpf(M)) cout << "bisa\n";
    else cout << "tidak bisa\n";

    return 0;
}