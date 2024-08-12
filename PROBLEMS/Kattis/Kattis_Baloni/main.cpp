#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll exist[1000005]; //exist[i] is the number of arrows currently flying at height i

int main() {
    fast_io();
    //use ll when possible!
    ll N; cin >> N;
    ll cnt = 0; //number of arrows needed to fire
    for (ll i = 1; i <= N; i++) {
        ll h; cin >> h;
        if (exist[h] == 0) {
            cnt++;
            exist[h-1]++;
        } else {
            exist[h]--;
            exist[h-1]++;
        }
    }

    cout << cnt << "\n";

    return 0;
}