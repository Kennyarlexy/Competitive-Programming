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
    vector<pair<ll, ll>> test = {{1, 10}, {2, 20}, {3, 30}};

    for (auto& [u, v] : test) {
        cout << u << " " << v << "\n";
    }

    return 0;
}