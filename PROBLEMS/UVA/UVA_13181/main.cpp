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
    string line;
    while (cin >> line) {
        vector<ll> used;
        ll len = line.length();
        for (ll i = 0; i < len; i++) {
            if (line[i] == 'X') used.push_back(i);
        }

        ll between = LONG_LONG_MIN;
        for (ll i = 1; i < used.size(); i++) {
            between = max(between, (used[i]-used[i-1]) / 2 - 1);
        }

        
        between = max(between, max(used[0]-1, len-used.back()-2));
        cout << between << "\n";
    }

    return 0;
}