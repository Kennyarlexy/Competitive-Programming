#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second 
using namespace std;

map<ll, vector<ll>> MP;
ll L[100005], R[100005];

ll f(vector<ll> &V) {
    ll m = V.size();
    if (m == 1) return 0;

    L[0] = -V[0];
    for (int i = 1; i < m; i++) {
        if (i % 2 == 1) L[i] = L[i-1] + V[i];
        else L[i] = L[i-1] - V[i];
    }

    R[m-1] = V[m-1];
    ll j = 0;
    for (int i = m-2; i >= 0; i--) {
        if (j % 2 == 0) R[i] = R[i+1] - V[i];
        else R[i] = R[i+1] + V[i];
        j++;
    }

    ll mn = LLONG_MAX;
    for (int i = 0; i < m; i++) {
        ll left = (i > 0) ? L[i-1] : 0;
        ll right = (i < m-1) ? R[i+1] : 0;
        mn = min(mn, left + right);
    }

    // for (int i = 0; i < 5; i++) cout << R[i] << " \n"[i==4];

    // cout << "mn = " << mn << "\n";
    // assert(mn >= 0);

    return mn;
}

ll g(vector<ll> &V) {
    ll m = V.size();
    ll X = 0;

    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) X -= V[i];
        else X += V[i];
    }

    assert(X >= 0);
    return X;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        MP = {};
        
        ll n, k; cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            ll x; cin >> x;
            MP[x % k].push_back(x);
        }

        ll cnt = 0;
        ll ans = 0;
        for (auto &[x, V] : MP) {
            sort(V.begin(), V.end());
            if (V.size() % 2 == 1) {
                ans += f(V)/k;
                cnt++;
            } else ans += g(V)/k;
        }
        if (cnt > 1) cout << "-1\n";
        else if (cnt == 0) {
            cout << ans << "\n";
        } else {
            if (n % 2 == 0) cout << "-1\n";
            else cout << ans << "\n";
        }
    }
    
    return 0;
}