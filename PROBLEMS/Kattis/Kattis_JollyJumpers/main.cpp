#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[3005];
bool exist[3005];

int main() {
    fast_io();
    //use ll when possible!

    string line;
    while (getline(cin, line)) {
        memset(exist, 0, sizeof(exist));
        stringstream SS(line);
        ll n; SS >> n;
        for (ll i = 1; i <= n; i++) {
            SS >> A[i];
        }

        for (ll i = 2; i <= n; i++) {
            ll diff = abs(A[i] - A[i-1]);
            if (diff < n) exist[diff] = true;
        }

        bool OK = true;
        for (ll i = 1; i < n; i++) {
            if (!exist[i]) {
                OK = false;
                break;
            }
        }

        cout << (OK ? "Jolly" : "Not jolly") << "\n";
    }

    return 0;
}