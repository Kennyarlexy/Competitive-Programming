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
            if (i > n/2) S.insert(A[i]);
        }

        ll x = (1LL << 31) - 1;
        ll ans = 0;
        for (int i = 1; i*2 <= n; i++) {
            
            auto itr = S.find(x-A[i]);
            if (itr != S.end()) {
                ans++;
                S.erase()
            }
        }
    }
    
    return 0;
}