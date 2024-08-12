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

        vector<int> dp_now(35, 0), dp_past(35, 0);
        for (int i = 1; i <= n; i++) {
            swap(dp_now, dp_past);
            for (int j = 0; j <= 30; j++) {
                dp_now[j] = dp_past[j];
                if (j - A[i].W >= 0) dp_now[j] = max(dp_now[j], dp_past[j-A[i].W] + A[i].P);
            }
        }

        ll sum = 0;
        for (int i = 1; i <= k; i++) {
            sum += dp_now[B[i]];
        }

        cout << sum << "\n";
    }
    
    return 0;
}