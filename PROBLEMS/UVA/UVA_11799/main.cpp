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
    ll T; cin >> T;
    cin.ignore(100, '\n');
    for (ll t = 1; t <= T; t++) {
        string line;
        getline(cin, line);
        stringstream SS(line);

        ll a;
        ll Max = 0;
        while (SS >> a) Max = max(Max, a);
        cout << "Case " << t << ": " << Max << "\n";
    }

    return 0;
}