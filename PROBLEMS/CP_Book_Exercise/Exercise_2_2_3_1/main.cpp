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
    cout << "1:\n";
    ll N = (1LL << 2); // 2^2
    ll X = 7;
    ll res = X & (N-1);
    cout << res << "\n";
    cout << "\n";

    cout << "2:\n";
    ll A = 128;
    ll B = 129;
    cout << (__builtin_popcountll(A) == 1 ? "pow of 2" : "not pow of 2") << "\n";
    cout << (__builtin_popcountll(B) == 1 ? "pow of 2" : "not pow of 2") << "\n";
    cout << "\n";

    cout << "3:\n";
    ll C = 40;
    cout << C - (C & -C) << "\n";
    cout << "\n";

    cout << "4:\n";
    ll D = 41;
    ll _D = ~D;
    D |= ((_D & -_D));
    cout << D << "\n";
    cout << "\n";

    cout << "5:\n";
    ll E = 39;
    ll _E = ~E;
    E ^= ((_E & -_E) - 1);
    cout << E << "\n";
    cout << "\n";

    cout << "6:\n";
    ll F = 36;
    F |= ((F & -F) - 1);
    cout << F << "\n";

    return 0;
}