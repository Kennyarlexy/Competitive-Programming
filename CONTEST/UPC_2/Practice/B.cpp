#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int a, b; cin >> a >> b;
    int c = max(a, b) + abs(a-b);
    cout << c << "\n";

    return 0;
}