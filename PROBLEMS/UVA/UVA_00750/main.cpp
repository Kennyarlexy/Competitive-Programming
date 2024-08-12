#include <bits/stdc++.h>
using namespace std;

int _r, _c;

int ans[10];
bitset<30> ur, udl, udr; // used row, used diagonal left, used diagonal right

int cnt = 0;

void f(int c) {
    if (c > 8) {
        cout << setw(2) << ++cnt << setw(7) << ans[1] << " ";
        for (int i = 2; i <= 8; i++) {
            cout << ans[i] << " \n"[i==8];
        }
        return;
    }
    
    if (c == _c) f(c+1);
    else {
        for (int r = 1; r <= 8; r++) {
            if (ur[r] || udl[r+c] || udr[r-c+8]) continue;
            ans[c] = r;
            ur[r] = udl[r+c] = udr[r-c+8] = true;
            f(c+1);
            ur[r] = udl[r+c] = udr[r-c+8] = false;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;


    for (int t = 1; t <= T; t++) {
        cout << "SOLN       " << "COLUMN\n";
        cout << " #      ";
        for (int i = 1; i <= 8; i++) {
            cout << i << " \n"[i==8];
        }
        cout << "\n";

        ur.reset(); udl.reset(); udr.reset();
        cnt = 0;
        cin >> _r >> _c;

        ur[_r] = udl[_r + _c] = udr[_r - _c + 8] = true;
        ans[_c] = _r;
        f(1);
        if (t < T) cout << "\n";
    }

    
    return 0;
}