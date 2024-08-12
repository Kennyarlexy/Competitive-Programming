#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define LSOne(x) ((x) & (-x))
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m, k; cin >> n >> m >> k;

        set<int> A, B;
        vector<int> X, Y;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            if (A.count(x) == 0) X.push_back(x);
            A.insert(x);
        }

        for (int i = 1; i <= m; i++) {
            int y; cin >> y;
            if (B.count(y) == 0) Y.push_back(y);
            B.insert(y);
        }


        int len = min(X.size(), Y.size());
        if (len*2 < k) {
            cout << "NO\n";
        } else {
            sort(X.begin(), X.end());
            sort(Y.begin(), Y.end());
            bool ans = true;
            int j = 1;
            for (int i = 0; i < len && j <= k; i++) {
                if (X[i] > Y[i]) swap(X[i], Y[i]);
                
                if (X[i] != j) {
                    ans = false;
                    break;
                }

                j++;
                if (j > k) break;

                if (Y[i] != j) {
                    ans = false;
                    break;
                }

                j++;
                if (j > k) break;
                // if (X[i] != j || Y[i] != j+1) {
                //     ans = false;
                //     break;
                // }
                // j += 2;
            }

            cout << (ans ? "YES":"NO") << "\n";
        }
        
    }
    
    return 0;
}