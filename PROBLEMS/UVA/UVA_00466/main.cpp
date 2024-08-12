#include <bits/stdc++.h>
#define ll long long
using namespace std;

char A[15][15];
char B[15][15];

bool match(ll n) {
    for (ll r = 1; r <= n; r++) {
        for (ll c = 1; c <= n; c++) {
            if (A[r][c] != B[r][c]) return false;
        }
    }
    return true;
}

char C[15][15];
void rotate(ll n) {
    for (ll r = 1; r <= n; r++) {
        for (ll c = 1; c <= n; c++) {
            C[r][c] = A[r][c];
        }
    }

    for (ll r = 1; r <= n; r++) {
        for (ll c = 1; c <= n; c++) {
            A[r][c] = C[n-(c-1)][r];
        }
    }
}

void mirror(ll n) {
    for (ll c = 1; c <= n; c++) {
        ll h = 1, l = n;
        while (h < l) {
            swap(A[h][c], A[l][c]);
            h++; l--;
        }
    }
}

void print(ll n) {
    for (ll r = 1; r <= n; r++) {
        for (ll c = 1; c <= n; c++) {
            cout << A[r][c];
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    ll t = 0;
    while (cin >> n) {
        for (ll r = 1; r <= n; r++) {
            for (ll c = 1; c <= n; c++) {
                cin >> A[r][c];
            }

            for (ll c = 1; c <= n; c++) {
                cin >> B[r][c];
            }
        }

        ll rotation = 0;
        while (rotation <= 270 && !match(n)) {
            rotate(n);
            rotation += 90;
        }

        cout << "Pattern " << ++t << " was ";
        if (rotation == 0) {
            cout << "preserved.\n";
        } else if (rotation <= 270) {
            cout << "rotated " << rotation << " degrees.\n";
        } else {
            mirror(n);
            rotation = 0;
            while (rotation <= 270 && !match(n)) {
                rotate(n);
                rotation += 90;
            }

            if (rotation == 0) {
                cout << "reflected vertically.\n";
            } else if (rotation <= 270) {
                cout << "reflected vertically and rotated " << rotation << " degrees.\n";
            } else {
                cout << "improperly transformed.\n";
            }
        }
    }
    
    return 0;
}

/*
3
XXX XXX
... ...
... ...
*/