#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int P[200005];

int main() {
    fast_io();
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    sort(P, P + N, greater<int> ());
    ll res = 0;
    for (int i = 1; i < N; i+=2) {
        res += P[i-1];
    }

    if (N % 2 == 1) res += P[N-1];
    cout << res << "\n";

    return 0;
}