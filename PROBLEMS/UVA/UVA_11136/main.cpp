#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    while (true) {
        cin >> n;
        if (n == 0) break;

        ll res = 0;
        multiset<ll> PQ;
        for (ll i = 1; i <= n; i++) {
            ll k; cin >> k;
            for (ll j = 1; j <= k; j++) {
                ll a; cin >> a;
                PQ.insert(a);
            }

            auto high = --PQ.end();
            auto low = PQ.begin();
            res += *high - *low;
            PQ.erase(high);
            PQ.erase(low);
        }
        cout << res << "\n";
    }
    
    return 0;
}

/*
5
3 1 2 3
2 1 1
4 10 5 5 1
0
1 2
2
2 1 2
2 1 2
0
*/