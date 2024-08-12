#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[55];

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll N; cin >> N;
        for (ll i = 1; i <= N; i++) {
            cin >> A[i];
        }

        ll low = 0, high = 0;
        for (ll i = 2; i <= N; i++) {
            if (A[i] > A[i-1]) high++;
            else if (A[i] < A[i-1]) low++;
        }

        cout << "Case " << t << ": " << high << " " << low << "\n";
    }    

    return 0;
}