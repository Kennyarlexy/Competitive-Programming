#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

unordered_map<ll, unordered_map<ll, ll>> MP1;
map<pair<ll, ll>, ll> MP2;

int main() {
    fast_io();
    //use ll when possible!
    ll R = 1e10, C = 1e10;
    // MP1.reserve(1005);
    // for (ll r = 1; r <= 1005; r++) {
    //     MP1[r].reserve(1005);
    // }

    auto __time_1 = chrono::high_resolution_clock::now();
    for (ll r = R; r <= R+1000; r++) {
        for (ll c = C; c <= C+1000; c++) {
            MP1[r][c] = (r+c)/2;
        }
    }

    //uncomment if you want to compare speed
    // for (ll r = R; r <= R+1000; r++) {
    //     for (ll c = C; c <= C+1000; c++) {
    //         MP2[{r, c}] = (r+c)/2;
    //     }
    // }
    auto __time_2 = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> exe_time_ms = __time_2 - __time_1;
    cout << exe_time_ms.count() << "ms\n";

    return 0;
}