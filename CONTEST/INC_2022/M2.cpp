//AC
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[100005];

int main() {
    fast_io();
    //use ll when possible!
    ll N; cin >> N;
    for (ll i = 1; i <= N; i++) {
        cin >> A[i];
    }

    ll res = 1;
    ll Max = 0;
    for (ll i = 1; i <= N; i++) {
        if (i % 2 == 1) Max++;
        else if (i == N) Max++;
        else if (abs(A[i-1] - A[i+1]) == 0 || abs(A[i-1] - A[i+1]) == 2) Max++;
        else {
            res = max(res, Max+1);
            Max = 1;
        }
        res = max(res, Max);
        // cout << Max << "\n";
    }
    cout << res << "\n";

    return 0;
}