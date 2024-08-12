#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

pair<int, int> A[15];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        for (int i = 1; i <= 4; i++) cin >> A[i].fi;
        A[1].se = A[2].se = 1;
        A[3].se = A[4].se = 2;

        sort(A+1, A+5);

        ll ans = 0;
        do {
            // if (A[1].se != 1 || A[2].se != 2 || A[3].se != 1 || A[4].se != 2) continue;

            if (A[1].se == 1 && A[2].se == 2 && A[3].se == 1 && A[4].se == 2) {
                int x = (A[1].fi > A[2].fi) + (A[3].fi > A[4].fi);
                int y = (A[1].fi < A[2].fi) + (A[3].fi < A[4].fi);

                if (x > y) {
                    // for (int i = 1; i <= 4; i++) cout << A[i].fi << " \n"[i==4];
                    ans++;
                }
            }

        } while (next_permutation(A+1, A+5));

        cout << ans << "\n";
    }
    
    return 0; 
}