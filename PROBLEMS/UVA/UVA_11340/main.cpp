#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        unordered_map<char, ll> MP;
        ll K; cin >> K;
        for (ll i = 1; i <= K; i++) {
            char ch; ll val;
            cin >> ch >> val;
            MP[ch] = val;
        }

        ll M; cin >> M;
        cin.ignore(1000, '\n');
        ll res = 0;
        for (ll i = 1; i <= M; i++) {
            string line;
            getline(cin, line);
            for (auto& ch : line) {
                res += MP[ch];
            }
        }

        cout << res/100 << ".";
        if (res % 100 < 10) cout << "0";
        cout << res % 100 << "$\n";
    }
    
    return 0;
}

/*
1
3
À 10
È 100
Û 1000
1
ÀÈÛÀÈÛÀÈÛÀÈÛÀÈÛÀÈÛÀÈÛÀÈÛÀÈÛÀÈÛÀÈÛÀÈÛÀÈÛÀÈÛÀÈÛÀÈÛÀÈÛ
*/