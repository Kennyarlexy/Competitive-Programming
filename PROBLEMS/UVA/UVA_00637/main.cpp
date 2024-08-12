#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;

ll A[105][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll P;
    while (true) {
        cin >> P;
        if (P == 0) break;

        memset(A, 0, sizeof(A));
        ll sheet = ((P+3) / 4) * 2;
        ll p = 1;
        ll sh = 1;
        bool side = true;
        while (sh <= sheet && p <= P) {
            A[sh][side] = p;
            sh++; p++;
            side = !side;
        }

        sh = sheet;
        while (sh >= 1 && p <= P) {
            A[sh][side] = p;
            sh--; p++;
            side = !side;
        }

        cout << "Printing order for " << P << " pages:\n";
        for (ll sh = 1; sh <= sheet; sh++) {
            if (A[sh][0] == 0 && A[sh][1] == 0) break;
            
            cout << "Sheet " << (sh+1) / 2 << ", " << (sh % 2 == 1 ? "front: " : "back : ");
            if (A[sh][0] == 0) cout << "Blank, ";
            else cout << A[sh][0] << ", ";
            if (A[sh][1] == 0) cout << "Blank\n";
            else cout << A[sh][1] << "\n";
        }
    }
    
    return 0;
}