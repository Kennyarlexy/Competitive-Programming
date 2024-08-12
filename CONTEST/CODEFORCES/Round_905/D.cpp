#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

multiset<int> L, R;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int Q; cin >> Q;

    int cnt = 0;
    for (int q = 1; q <= Q; q++) {
        char op; int l, r;
        cin >> op >> l >> r;
        int min_r, max_l;
        if (op == '+') {
            cnt++;
            L.insert(l);
            R.insert(r);
        } else {
            cnt--;
            L.erase(L.find(l));
            R.erase(R.find(r));
        }
        if (cnt <= 1) cout << "NO\n";
        else {
            min_r = *(R.begin());
            max_l = *(L.rbegin());
            if (min_r < max_l) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    
    return 0;
}