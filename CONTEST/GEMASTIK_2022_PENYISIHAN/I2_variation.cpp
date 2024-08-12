#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    //use ll when possible!
    ll N; cin >> N;
    string A, B; cin >> A >> B;
    ll cnt = 0;
    ll i = 0;
    while (i < N) {
        if (A[i] > B[i]) {
            while (i < N && A[i] >= B[i]) i++;
            cnt++;
        }
        i++;
    }

    cout << cnt << "\n";

    return 0;
}