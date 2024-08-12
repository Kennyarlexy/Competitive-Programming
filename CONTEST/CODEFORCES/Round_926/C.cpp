#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

bool f(ll k, ll x, ll a) {
    ll spend = x;
    ll profit = (a-spend)*(k-1) - spend;
    return profit >= 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll k, x, a; cin >> k >> x >> a;
        if ((k-x-1 >= 0 && a > x) || f(k, x, a)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}

/*
1 
99999 2 2
NO


*/