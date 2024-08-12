#include <bits/stdc++.h>
#define ll long long
using namespace std;

unordered_set<ll> res = {1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441,
1000000, 1771561, 2985984, 4826809, 7529536, 11390625, 16777216, 24137569, 34012224,
47045881, 64000000, 85766121};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll x;
    while (true) {
        cin >> x;
        if (x == 0) break;
        cout << (res.count(x) ? "Special" : "Ordinary") << "\n";
    }
    
    return 0;
}