#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

pair<int, char> query(ll x, ll y) {
    cout << "? " << x << " " << y << endl;
    int q; char ch; 
    cin >> q >> ch;

    return {q, ch};
}

void answer(ll x, ll y) {
    cout << "! " << x << " " << y << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll X, Y, N; cin >> X >> Y >> N;
    ll L = 0, R = X, D = 0, U = Y;
    bool OK = false;
    for (int i = 1; i <= N; i++) {
        ll OH = (L + R) / 2;
        ll OV = (U + D) / 2;
        auto [q, ch] = query(OH, OV);
    
        if (q == 1) {
            D = OV;
            L = OH;
        } else if (q == 2) {
            D = OV;
            R = OH;
        } else if (q == 3) {
            U = OV;
            R = OH;
        } else {
            U = OV;
            L = OH;
        }

        if (U - D == 1 && R - L == 1) {
            ll x = R, y = U;
            
            if (ch == 'U') y++;
            else if (ch == 'D') y--;
            else if (ch == 'L') x--;
            else if (ch == 'R') x++;

            answer(x, y);
            OK = true;
            break;
        }

        if (ch == 'U') {
            U = min(Y, U+1);
            D++;
        } else if (ch == 'D') {
            D = max(0LL, D-1);
            U--;
        } else if (ch == 'L') {
            L = max(0LL, L-1);
            R--;
        } else if (ch == 'R') {
            R = min(X, R+1);
            L++;
        }
    }

    if (!OK) assert(0);
    
    return 0;
}