#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    map<int, int> maps;
    int val = 101;
    for (int i = 0; i < 100; i++) {
        maps.insert({i, val});
        val++;
    }

    for (auto& data : maps) {
        cout << data.second << "\n";
    }

    return 0;
}