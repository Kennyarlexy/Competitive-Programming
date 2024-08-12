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
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A, A + N);
    for (ll i = 0; i < N; i++) {
        cout << A[i];
        if (i < N - 1) cout << " ";
    }
    cout << "\n";

    return 0;
}