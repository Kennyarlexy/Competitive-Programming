#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll cnt[105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    while (true) {
        cin >> n;
        if (n == 0) break;

        memset(cnt, 0, sizeof(cnt));
        for (ll i = 1; i <= n; i++) {
            ll a; cin >> a;
            cnt[a]++;
        }

        bool flag = false;
        for (ll i = 1; i <= 100; i++) {
            while (cnt[i] > 0) {
                if (flag) cout << " ";
                cout << i;
                cnt[i]--;
                flag = true;
            }
        }
        cout << "\n";
    }
    
    return 0;
}