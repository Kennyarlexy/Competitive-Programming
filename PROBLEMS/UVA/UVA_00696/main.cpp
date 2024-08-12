#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll R, C;
    while (cin >> R >> C) {
        if (R == 0 && C == 0) break;

        if (R == 1) cout << C;
        else if (C == 1) cout << R;
        else if (R == 2) {
            // all are correct (AC)
            // cout << ((C+2) / 4) * 4 + ((C % 4 == 1) * 2);
            // cout << ((C+2) - ((C+2) % 4)) + ((C % 4 == 1) * 2);
            cout << ((C+3)/4)*2 + ((C+2)/4)*2; //prefered, think this as how to place 2*1 blocks with interval of 4
        }
        else if (C == 2) {
            // all are correct (AC)
            // cout << ((R+2) / 4) * 4 + ((R % 4 == 1) * 2);
            // cout << ((R+2) - ((R+2) % 4)) + ((R % 4 == 1) * 2);
            cout << ((R+3)/4)*2 + ((R+2)/4)*2;
        }
        else {
            cout << (R/2) * C + (R % 2) * ((C + 1)/2);
        }
        cout << " knights may be placed on a " << R << " row " << C << " column board.\n";
    }
    
    return 0;
}