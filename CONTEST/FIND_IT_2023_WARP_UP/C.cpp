#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        string x; cin >> x;
        ll len = x.length();
        if (len == 1) {
            cout << x << " " << x << "\n";
            continue;
        }

        bool _max = false;
        for (ll i = len-1; i-1 >= 0; i--) {
            ll sum = x[i] + x[i-1] - 2*'0';
            if (sum >= 10) {
                cout << x.substr(0, i-1) << sum << x.substr(i+1);
                _max = true;
                break;
            }
        }

        if (!_max) { // if 2 digit sum not found
            ll sum = x[0] + x[1] - 2*'0';
            cout << sum << x.substr(2);
        }

        cout << " ";

        bool _min = false;
        for (ll i = len-1; i-1 >= 0; i--) {
            ll sum = x[i] + x[i-1] - 2*'0';
            if (sum < 10) {
                cout << x.substr(0, i-1) << sum << x.substr(i+1);
                _min = true;
                break;
            }
        }

        if (!_min) { // if 1 digit sum not found
            ll sum = x[0] + x[1] - 2*'0';
            cout << sum << x.substr(2);
        }
        
        cout << "\n";
    }
    
    return 0;
}