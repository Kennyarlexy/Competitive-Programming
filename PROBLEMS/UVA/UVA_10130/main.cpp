#include <bits/stdc++.h>
#define ll long long
#define P first
#define W second
using namespace std;

pair<int, int> A[1005];
int B[105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i].P >> A[i].W;
        }

        int k; cin >> k;
        for (int i = 1; i <= k; i++) {
            cin >> B[i];
        }

        vector<int> dp_now(35, -1), dp_past(35, -1);
        dp_now[0] = 0, dp_now[A[1].W] = A[1].P;
        for (int i = 2; i <= n; i++) {
            dp_past = dp_now;
            for (int j = 0; j <= 30; j++) {
                if (j - A[i].W < 0) dp_now[j] = dp_past[j];
                else {
                    dp_now[j] = (dp_past[j-A[i].W] == -1) ? dp_past[j] : max(dp_past[j-A[i].W] + A[i].P, dp_past[j]);
                }
            }
        }

        ll sum = 0;
        for (int i = 1; i <= k; i++) {
            ll mx = 0;
            for (int j = 0; j <= B[i]; j++) {
                if (dp_now[j] != -1) mx = max(mx, (ll) dp_now[j]);
            }
            sum += mx;
        }

        cout << sum << "\n";
    }
    
    return 0;
}