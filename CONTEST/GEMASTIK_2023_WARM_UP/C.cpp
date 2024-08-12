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
    bool state = false;
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] > B[i]) {
            state = true;
        } else if (A[i] < B[i] && state) {
            state = false;
            cnt++;
        }
    }

    if (state) cnt++;
    cout << cnt << "\n";

    return 0;
}