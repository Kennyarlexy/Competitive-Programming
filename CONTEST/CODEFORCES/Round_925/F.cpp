#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second 

using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, k; cin >> n >> k;
        vector<vector<int>> A;
        for (int i = 0; i < k; i++) {
            A.push_back({});
            for (int j = 1; j < n; j++) {
                int a; cin >> a;
                A[i].push_back(a);
            }
        }

        bool ans = true;
        for (int j = n-1; j >= 0; j--) {
            map<int, int> MP;
            for (int i = 0; i < k; i++) {
                MP[A[i][j]]++;
            }

            if (MP.size() > 2) {
                ans = false;
                break;
            }

            for (auto [x, cnt] : MP) {
                ll k = min(cnt, n-cnt);
                if (k > n-j) {
                    ans = false;
                    break;
                }
            }
        }
        cout << (ans ? "YES":"NO") << "\n";
    }
    
    return 0;
}