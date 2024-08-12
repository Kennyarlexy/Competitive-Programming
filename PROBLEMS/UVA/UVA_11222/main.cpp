#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll score[5];
ll cnt[10005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        memset(score, 0, sizeof(score));
        memset(cnt, 0, sizeof(cnt));

        vector<ll> A[4];
        for (ll i = 1; i <= 3; i++) {
            ll n; cin >> n;
            A[i].resize(n);
            for (auto& d : A[i]) {
                cin >> d;
                cnt[d]++;
            }
        }

        ll _max = 0;
        for (ll i = 1; i <= 3; i++) {
            for (auto& d : A[i]) {
                if (cnt[d] == 1) score[i]++;
            }

            _max = max(_max, score[i]);
        }

        cout << "Case #" << t << ":\n";
        for (ll i = 1; i <= 3; i++) {
            if (score[i] == _max) {
                cout << i << " " << score[i];
                sort(A[i].begin(), A[i].end());
                for (auto& d : A[i]) {
                    if (cnt[d] != 1) continue;
                    cout << " " << d;
                }
                cout << "\n";
            }
        }
    }
    
    return 0;
}