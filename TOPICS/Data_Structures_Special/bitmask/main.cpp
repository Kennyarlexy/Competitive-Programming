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
    ll A = 10000000000000123LL;
    ll B = A;

    auto __time_1 = chrono::high_resolution_clock::now();
    for (ll i = 1; i <= 100000000; i++) {
        A /= 2;
        A *= 2;
    }
    auto __time_2 = chrono::high_resolution_clock::now();

    auto __time_3 = chrono::high_resolution_clock::now();
    for (ll i = 1; i <= 100000000; i++) {
        B = (B >> 1);
        B = (B << 1);
    }
    auto __time_4 = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> exe_time_ms1 = __time_2 - __time_1;
    chrono::duration<double, std::milli> exe_time_ms2 = __time_4 - __time_3;
    cout << A << " " << B << "\n";
    cout << exe_time_ms1.count() << "ms\n";
    cout << exe_time_ms2.count() << "ms\n";

    return 0;
}