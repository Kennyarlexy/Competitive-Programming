#include <bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<string, ll> MP;

int main() {
    ll p, g; cin >> p >> g;
    for (ll i = 1; i <= p; i++) {
        string s; cin >> s;
        ll x, y; //x.y
        scanf(" %lld.%lld", &x, &y);
        MP[s] = 10*x + y;
    }

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (ll i = 1; i <= g; i++) {
        string s, op;
        ll sum = 0;
        while (true) {
            cin >> s >> op;
            sum += MP[s];
            if (op[0] != '+') break;
        }
        ll check; cin >> check;
        check *= 10;
        cout << "Guess #" << i << " was ";
        if (op == "<" && sum < check) {
            cout << "correct.\n";
        } else if (op == ">" && sum > check) {
            cout << "correct.\n";
        } else if (op == "<=" && sum <= check) {
            cout << "correct.\n";
        } else if (op == ">=" && sum >= check) {
            cout << "correct.\n";
        } else if (op == "=" && sum == check) {
            cout << "correct.\n";
        } else {
            cout << "incorrect.\n";
        }
        // cout << sum << " " << op << " " << check << "\n";
    }
    
    return 0;
}