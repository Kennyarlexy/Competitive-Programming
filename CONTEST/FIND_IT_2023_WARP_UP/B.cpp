#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    cin.ignore(1000, '\n');
    for (ll t = 1; t <= T; t++) {
        memset(A, 0, sizeof(A));
        string line;
        getline(cin, line);
        stringstream SS(line);
        ll h;
        ll cnt = 0;
        while (SS >> h) {
            if (A[h+1] > 0) {
                A[h+1]--;
                A[h]++;
            } else {
                cnt++;
                A[h]++;
            }
        }
        cout << cnt << "\n";
    }
    
    return  0;
}