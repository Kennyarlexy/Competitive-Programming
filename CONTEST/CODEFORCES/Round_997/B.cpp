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
        int n; cin >> n;
        vector<vector<char>> AM(n+1, vector<char> (n+1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> AM[i][j];
            }
        }

        vector<vector<int>> ans(n+1);
        vector<bool> used(n+1, false);

        for (int i = 1; i <= n; i++) {
            if (used[i]) continue;

            ans[i].push_back(i);
            used[i] = true;
            for (int j = i+1; j <= n; j++) {
                if (AM[i][j] == '1' && !used[j]) {
                    ans[i].push_back(j);
                    used[j] = true;
                }
            }
        }

        for (int i = n; i >= 1; i--) {
            for (auto x : ans[i]) {
                cout << x << " ";
            }
        }
        cout << "\n";
    }
    
    return 0;
}