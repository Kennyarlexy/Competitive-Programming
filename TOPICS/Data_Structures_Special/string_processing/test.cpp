#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

map<ll, ll> MP;

int main() {
    fast_io();
    //use ll when possible!
    for (ll i = 1; i <= 1000000; i++) {
        map<ll, ll>::iterator it; bool in;
        tie(it, in) = MP.insert({i, i*10});
    }

    for (ll i = 1000; i <= 2000; i++) {
        MP[i] = -1000;
    }
    auto __time_1 = chrono::high_resolution_clock::now();
    ll min = -1000;
    for (auto& [k, v] : MP) {
        if (v == min) cout << k << "\n";
    }

    auto __time_2 = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> exe_time_ms = __time_2 - __time_1;
    cout << exe_time_ms.count() << "ms\n";
    cout << MP.size() << "\n";

    return 0;
}