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
        vector<int> cnt(n+1, 0);
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                char ch; cin >> ch;
                if (j > i && ch == '1') cnt[i]++;
            }
        }
        
        vector<int> ans; ans.reserve(n+1);
        for (int i = n; i >= 1; i--) {
            ans.push_back(i);
            int j = ans.size() - 1;
            for (int k = 1; k <= cnt[i]; k++) {
                swap(ans[j], ans[j-1]);
                j--;
            }
        }

        for (auto an : ans) {
            cout << an << " ";
        }
        cout << "\n";
    }
    
    return 0;
}