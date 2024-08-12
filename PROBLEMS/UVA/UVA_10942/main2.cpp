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
        vector<tuple<ll, ll, ll>> res;
        do {
            if (A[1] == 0 || A[1] > 12)
                continue;
            ll year = c*100 + A[2];
            bool leap_year = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
            dim[2] = (leap_year ? 29 : 28);

            if (A[0] == 0 || A[0] > dim[A[1]%12])
                continue;

            res.push_back({A[2], A[1], A[0]});
        } while (next_permutation(A, A+3));

        if (res.size() > 0) {
            sort(res.begin(), res.end());
            ll YY = get<0>(res[0]);
            ll MM = get<1>(res[0]);
            ll DD = get<2>(res[0]);
            cout << (YY < 10 ? "0" : "") << YY << " " << (MM < 10 ? "0" : "") << MM << " " << (DD < 10 ? "0" : "") << DD << "\n";
        }
        else
            cout << "-1\n";
    }
    
    return 0;
}