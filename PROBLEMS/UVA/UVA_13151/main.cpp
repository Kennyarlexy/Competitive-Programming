#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string n;
    ll k;
    while (true) {
        cin >> n >> k;
        if (n == "0" && k == 0) break;

        ll i;
        stringstream SS(n);
        if (n.length() >= 2 && n[1] == 'x') SS >> hex >> i;
        else if (n[0] == '0') SS >> oct >> i;
        else SS >> i;

        ll score = 0;
        for (ll j = 1; j <= k; j++) {
            string op;
            ll out;
            cin >> op >> out;
            if (op == "i++") {
                if (i++ == out) score++;
                else i = out + 1;
            } else if (op == "++i") {
                if (++i == out) score++;
                else i = out;
            } else if (op == "i--") {
                if (i-- == out) score++;
                else i = out - 1;
            } else if (op == "--i") {
                if (--i == out) score++;
                else i = out;
            } else {
                if (i == out) score++;
                else i = out;
            }
        }
        cout << score << "\n";
    }
    
    return 0;
}