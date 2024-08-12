#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[20005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll x = 0;
    while (true) {
        ll cycle;
        ll n = 0;
        memset(A, 0, sizeof(A));
        ll _min = LONG_LONG_MAX;
        while (true) {
            cin >> cycle;
            if (cycle == 0) {
                x++;
                break;
            }
            x = 0;
            n++;
            ll Cycle = 2*cycle;
            _min = min(_min, Cycle);
            for (ll i = 0; i <= 18000; i+=Cycle) {
                A[i]++;
                A[i+cycle-5]--;
            }
        }

        if (x > 3) break;
        if (n == 0) continue;
        for (ll i = 1; i <= 18000; i++) {
            A[i] += A[i-1];
        }

        bool sync = false;
        for (ll i = _min; i <= 18000; i++) {
            if (A[i] == n) {
                sync = true;
                ll h = i / 3600;
                ll m = (i-h*3600) / 60;
                ll s = i % 60;

                cout << "0" << h << ":" << (m < 10 ? "0" : "") << m << ":" << (s < 10 ? "0" : "") << s << "\n";
                break;
            }
        }
        if (!sync) cout << "Signals fail to synchronise in 5 hours\n";
    }
    
    return 0;
}