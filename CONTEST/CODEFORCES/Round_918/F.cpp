#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,
    tree_order_statistics_node_update> indexed_set;

pair<int, int> P[200005];

bool cmp(pair<int, int> A, pair<int, int> B) {
    return A.se > B.se;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        indexed_set S;
        for (int i = 1; i <= n; i++) {
            cin >> P[i].fi >> P[i].se;
            S.insert(-P[i].fi); // because we want it to be descending
        }

        sort(P+1, P+n+1, cmp);

        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ll rank = S.order_of_key(-P[i].fi); // initial rank, at t = 0, this will also be the change of rank
            
            ans += rank; 
            S.erase(-P[i].fi); // we remove this since P[i].fi is now the current "top" rank and all elements after this rank should be shifted (so we won't overcounting the change of rank)
        }

        cout << ans << "\n";
    }
    
    return 0;
}