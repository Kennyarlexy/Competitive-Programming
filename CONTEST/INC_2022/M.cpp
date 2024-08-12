//WA
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
    ll Max = 1;
    // ll start = 0, stop = 0;
    bool part_of_seg  = false;
    for (ll i = 3; i <= N; i+=2) {
        if (abs(A[i] - A[i-2]) == 2 || abs(A[i] - A[i-2]) == 0) {
            Max += 2;
        }
        else Max = 1;
        res = max(res, Max);
    }

    if (Max == N-1) res++;
    else if (Max <= N-2) res+=2;

    // if (N > 3) res = max(3LL, res);
    cout << res << "\n";

    return 0;
}