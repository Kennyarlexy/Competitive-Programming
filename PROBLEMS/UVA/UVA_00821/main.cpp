#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 0;
    
    while (true) {
        vector<pair<int, int>> EL;
        set<int> S;
        vector<int> compress(101);
        int x = 0;
        while (true) {
            int u, v; cin >> u >> v;
            if (u == 0 && v == 0) break;
            if (S.count(u) == 0) {
                compress[u] = x++;
                S.insert(u);
            }
            if (S.count(v) == 0) {
                compress[v] = x++;
                S.insert(v);
            }
            EL.push_back({compress[u], compress[v]});
        }

        if (EL.empty()) break;
        int M = EL.size();
        vector<vector<int>> AM(x, vector<int> (x, INF));
        
        for (auto [u, v]: EL) {
            AM[u][v] = 1;
        }
        
        for (int k = 0; k < x; k++) {
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < x; j++) {
                    AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);
                }
            }
        }

        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < x; j++) {
                if (i == j) continue;
                sum += AM[i][j];
                cnt++;
            }
        }

        double ans = (double) sum / (double) cnt;
// cout << "M = " << M << "   x = " << x << "   sum = " << sum << "\n";
        cout << "Case " << ++t << ": " << "average length between pages = " << fixed << setprecision(3) << ans << " clicks\n";
    }
    
    return 0;
}