#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    //use ll when possible!
    ll N, Q; cin >> N >> Q;
    map<string, ll> MP;
    ll id = 0;
    for (ll i = 1; i <= N; i++) {
        string s; cin >> s;
        MP.emplace(s, ++id);
    }

    for (ll i = 1; i <= Q; i++) {
        string s; cin >> s;
        auto it = MP.find(s);
        if (it != MP.end()) {
            cout << it->second << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}