#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll B[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, k; cin >> n >> k;
        vector<bool> vis(n+5);
        for (int i = 1; i <= n; i++) {
            cin >> B[i];
        }

        int j = n;
        bool OK = true;
        for (int i = 1; i <= min(n, k); i++) {
            if (vis[j]) break;
            if (B[j] > n) {
                OK = false;
                break;
            }
            vis[j] = true;
            j -= B[j];
            if (j < 1) j += n;
        }

        cout << (OK ? "Yes" : "No") << "\n";
    }
    
    return 0;
}