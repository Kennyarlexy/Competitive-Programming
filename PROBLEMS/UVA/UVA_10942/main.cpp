#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[5];
ll dim[] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll c;
        cin >> c >> A[0] >> A[1] >> A[2];
        sort(A, A + 3);

        bool OK = false;
        ll _min = LONG_LONG_MAX;
        ll DD, MM, YY;
        do {
            if (A[1] == 0 || A[1] > 12)
                continue;
            ll year = c*100 + A[2];
            bool leap_year = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
            dim[2] = (leap_year ? 29 : 28);

            if (A[0] == 0 || A[0] > dim[A[1]%12])
                continue;
    
            ll days = (year-1)*365 + (year-1)/4 - (year-1)/100 + (year-1)/400 + A[0];

            for (ll i = 1; i < A[1]; i++) {
                days += dim[i];
            }

            if (days < _min) {
                _min = days;
                DD = A[0], MM = A[1], YY = A[2];
            }
            OK = true;
        } while (next_permutation(A, A+3));

        if (OK)
            cout << (YY < 10 ? "0" : "") << YY << " " << (MM < 10 ? "0" : "") << MM << " " << (DD < 10 ? "0" : "") << DD << "\n";
        else
            cout << "-1\n";
    }
    
    return 0;
}