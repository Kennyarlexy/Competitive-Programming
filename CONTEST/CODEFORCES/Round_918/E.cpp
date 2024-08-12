#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[200005], O[200005], E[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        for (int i = 1; i <= n; i++) {
            O[i] = O[i-1];
            E[i] = E[i-1];
            if (i % 2 == 0) E[i] += A[i];
            else O[i] += A[i];
        }

        int l = 1, r = n;
        bool OK = false;
        while (l <= r) {
            ll sum_odd = O[r] - O[l-1];
            ll sum_even = E[r] - E[l-1];



            if (sum_odd == sum_even) {
                OK = true;
                break;
            }

            
        }
    }
    
    return 0;
}