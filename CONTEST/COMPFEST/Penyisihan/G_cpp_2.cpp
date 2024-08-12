#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll N;
// pair<ll, ll> getN(ll X) {
//     ll cnt = 0;
//     ll D = 1;
//     ll fin_max = LONG_LONG_MIN;
//     while (true) {
//         ll seq_start = D*(D + 2);
//         if (seq_start > X) break;

//         ll n = (X-seq_start + 2*D) / 2*D;
//         cnt += n;
//         fin_max = max(fin_max, seq_start + (n-1)*2*D);
//         D++;
//     }

//     return {cnt, fin_max};
// }

int main() {
    fast_io();
    //use ll when possible!
    cin >> N; 
    ll start = 3;
    ll res = 0;
    for (ll step = 100; step >= 1; step/=2) {
        // cout << "currently checking " << start + step << "\n";
        while(true) {
            ll cnt = 0;
            ll D = 1;
            ll seq_max = LONG_LONG_MIN;
            while (true) {
                ll seq_start = D*(D + 2);
                if (seq_start > start+step) break;

                ll n = (start+step-seq_start) / (2*D) + 1;
                cout << "n for " << start + step << " with seq_start = " << seq_start << " and D = " << D << " = " << n << "\n";
                cnt += n;
                seq_max = max(seq_max, seq_start + (n-1)*2*D);
                D++;
            }
            cout << "total cnt = " << cnt << "\n";
            cout << "end\n";
            if (cnt > N) break;
            start += step;
            res = seq_max;
        }

        


        // ll cnt = 0;
        // tie(cnt, res) = getN(start+step);
        // while (cnt <= N){
        //     cout << cnt << "\n";
        //     start += step;
        //     tie(cnt, res) = getN(start+step);
        // }
    }

    cout << res << "\n";

    return 0;
}