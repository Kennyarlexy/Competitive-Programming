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
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        string A, B; cin >> A >> B;
        ll cnt_0_1 = 0, cnt_1_0 = 0, k = 0;
        ll cnt_0_A = 0, cnt_0_B = 0;
        for (ll i = 0; i < A.length(); i++) {
            if (A[i] == '0' && B[i] == '1') cnt_0_1++;
            else if (A[i] == '1' && B[i] == '0') cnt_1_0++;
            else if (A[i] == '?') k++;

            if (A[i] == '0') cnt_0_A++;
            if (B[i] == '0') cnt_0_B++;
        }

        cout << "Case " << t << ": ";
        if (cnt_0_A + k < cnt_0_B) cout << "-1\n";
        else cout << min(cnt_0_1, cnt_1_0) + abs(cnt_0_1- cnt_1_0) + k << "\n"; 
    }

    return 0;
}