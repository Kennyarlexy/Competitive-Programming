#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

ll n_bit, n_var;
map<string, ull> value;
string var[1005];
ll n_byte[1005];

ull f(string bin) {
    ull val = 0;
    reverse(bin.begin(), bin.end());
    for (ll i = 0; i < bin.size(); i++) {
        if (bin[i] == '1') val |= (1ULL << i);
    }
    return val;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n_bit >> n_var) {
        value = {};
        for (ll i = 1; i <= n_var; i++) {
            cin >> var[i] >> n_byte[i];
        }

        for (ll i = 1; i <= n_var; i++) {
            string bin;
            for (ll j = 1; j <= n_byte[i]; j++) {
                string temp; cin >> temp;
                bin += temp;
            }
            value[var[i]] = f(bin);
        }

        ll Q; cin >> Q;
        for (ll q = 1; q <= Q; q++) {
            string s; cin >> s;
            auto it = value.find(s);
            cout << s << "=";
            if (it != value.end()) cout << it->second;
            cout << "\n";
        }
    }
    
    return 0;
}

/*
4 4
ab 2
Cd 2
ef 3
gh 1
0101
1111
1111
0101
1010
1010
1010
1000
4
Ab
Cd
ef
gh
*/