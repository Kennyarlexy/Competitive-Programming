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
    string num;
    while (true) {
        cin >> num;
        if (num == "END") break;

        if (num == "1") {
            cout << "1\n";
        } else {
            ll i = 1;
            ll xi = num.length();
            while (xi != 1) {
                i++;
                xi = to_string(xi).length();
            }
            cout << i + 1 << "\n";
        }
    }

    return 0;
}