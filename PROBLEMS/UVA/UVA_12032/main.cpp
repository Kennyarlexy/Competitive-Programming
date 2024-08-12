#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[100005];

bool f(ll k, ll n) {
    for (int i = 1; i <= n; i++) {
        if (A[i] - A[i-1] > k) return false;
        if (A[i] - A[i-1] == k) k--;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) cin >> A[i];

        ll k = 1e8;
        for (ll step = 1e5; step > 0; step /= 2) {
            while (k-step > 0 && f(k-step, n)) k -= step;
        }

        cout << "Case " << t << ": " << k << "\n";
    }
    
    return 0;
}