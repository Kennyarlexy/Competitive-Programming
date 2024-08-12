#include <bits/stdc++.h>
#define ll long long
using namespace std;

#include <bits/extc++.h> // pbds
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ost;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ost tree;

    for (ll i = 1; i <= 2000000; i+=2) {
        tree.insert(i);
    }

    ll i = 1;
    while (i < tree.size()) {
        ll j = *tree.find_by_order(i) - 1;
        ll step = j;
        while (j < tree.size()) {
            tree.erase(*tree.find_by_order(j));
            j += step;
        }
        i++;
    }

    bool flag = false;
    for (auto& d : tree) {
        if (flag) cout << ", ";
        cout << d;
        flag = true;
    }

    cout << "\n";
    
    return 0;
}