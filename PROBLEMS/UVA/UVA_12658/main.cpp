#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

string A[10];

int main() {
    fast_io();
    //use ll when possible!
    ll n; cin >> n;
    for (ll i = 1; i <= 5; i++) {
        cin >> A[i];        
    }

    for (ll j = 0; j < A[4].length(); j+=4) {
        if (A[4][j] == '*') cout << "2";
        else if (A[4][j+1] == '*') cout << "1";
        else cout << "3";
    }
    cout << "\n";

    return 0;
}