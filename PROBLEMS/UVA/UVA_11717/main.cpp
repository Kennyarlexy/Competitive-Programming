#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll n, i, k; cin >> n >> i >> k;
        ll L = -1, R = -1; //activation period
        ll prev = 0;
        
        ll i_cnt = 0;
        ll ignored = 0;
        
        for (ll j = 1; j <= n; j++) {
            ll time; cin >> time;
            if (time - prev >= i) {
                i_cnt++;
                L = time;
                R = L + k;
                prev = time + k;
            } else if (time >= L && time < R) {
                ignored++;
            } else {
                prev = time;
            }
        }

        cout << "Case " << t << ": " << i_cnt << " " << ignored << "\n";
    }
    
    return 0;
}

/*
#1
1
5 1 1
2
4
6
8
10

#2
1
10 1 1
1
2
3
4
5
6
7
8
9
10

#3
1
7 1 2
2 4 6 8 10 11 12

#4
1
1 1 1
0
*/