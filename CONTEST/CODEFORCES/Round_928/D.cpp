#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

ll A[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        multiset<ll> S;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            S.insert(A[i]);
        }

        ll x = (1LL << 31) - 1;
        ll ans = 0;

        multiset<ll>::iterator erased;
        bool f = false;
        for (auto i = S.begin(); i != S.end(); i++) {
            if (f) S.erase(erased);
            auto itr = S.find(x - (*i));
            if (itr != S.end()) {
                // cout << "A\n";
                S.erase(itr);
            } else {
                // cout << "B\n";
            }
            erased = i;
            f = true;
            ans++;
        }
        cout << ans << "\n";
    }
    
    return 0;
}

/*
1
3
0 0 2147483647
*/