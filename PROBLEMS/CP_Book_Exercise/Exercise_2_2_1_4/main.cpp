#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void print(ll B[105][105], ll n) {
    for (ll r = 0; r < n; r++) {
        for (ll c = 0; c < n; c++) {
            cout << B[r][c] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

ll A[105][105];

int main() {
    fast_io();
    //use ll when possible!
    srand(time(NULL));
    ll n = 10;
    for (ll r = 0; r < n; r++) {
        for (ll c = 0; c < n; c++) {
            A[r][c] = rand() % n;
        }
    }

    for (ll r = 0; r < n; r++) {
        for (ll c = 0; c < n; c++) {
            cout << A[r][c] << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    cout << "1:\n";
    ll B[105][105];
    for (ll c = 0; c < n; c++) {
        for (ll r = n-1; r >= 0; r--) {
            B[c][n-1-r] = A[r][c];
        }
    }

    print(B, n);

    cout << "2:\n";
    for (ll r = 0; r < n; r++) {
        for (ll c = 0; c < n; c++) {
            B[r][c] = A[c][r];
        }
    }

    print(B, n);
    cout << "3:\n";
    for (ll r = 0; r < n; r++) {
        for (ll c = 0; c < n; c++) {
            B[r][c] = A[r][c];
        }
    }

    for (ll r = 0; r < n; r++) {
        reverse(A, A+n);
    }

    print(B, n);
    
    return 0;
}