#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

string f(ll n) {
    string res;
    for (ll i = 7; i >= 0; i--) {
        res += to_string((n & (1LL << i)) >= 1);
    }
    return res;
}

int main() {
    fast_io();
    //use ll when possible!
    ll num; cin >> hex >> num;
    cout << f(num) << "\n";

    return 0;
}