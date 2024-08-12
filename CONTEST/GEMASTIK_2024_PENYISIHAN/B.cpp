#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds; 
typedef tree<pair<ll, ll>,null_type,less<pair<ll, ll>>,rb_tree_tag, 
tree_order_statistics_node_update> indexed_set;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // rank by its right
    ll n, L; cin >> n >> L;
    indexed_set S;
    S.insert({L, L});

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        x--;
        auto y = S.find_by_order(x);
        
        ll right = y->first;
        ll len = y->second;

        // cout << "right = " << right << "   len = " << len << "\n";
        
        S.erase(y);

        pair<ll, ll> A = {right, len/2};
        pair<ll, ll> B = {right - len/2, len/2};
        S.insert(A); S.insert(B);
    }

    for (auto [right, len] : S) {
        cout << len << " ";
    }
    cout << "\n";
    
    return 0;
}