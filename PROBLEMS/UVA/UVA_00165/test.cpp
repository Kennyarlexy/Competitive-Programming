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
    auto __time_1 = chrono::high_resolution_clock::now();
    for (int i = 1; i <= 100000; i++) {
        bitset<1000> bit;
    }
    auto __time_2 = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> exe_time_ms = __time_2 - __time_1;
    cout << exe_time_ms.count() << "ms\n";

    return 0;
}