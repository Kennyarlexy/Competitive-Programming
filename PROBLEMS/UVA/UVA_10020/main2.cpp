#include <bits/stdc++.h>
#define ll long long
#define le first 
#define ri second
using namespace std;

vector<pair<int, int>> V;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    V.reserve(100005);
    int T; cin >> T;

    for (int t = 1; t <= T; t++) {
        int M; cin >> M;
        V.resize(0);
        while (true) {
            int a, b; cin >> a >> b;
            if (a == 0 && b == 0) break;
            if (b <= 0) continue;
            if (a > M) continue;
            V.push_back({a, b});
        }

        sort(V.begin(), V.end());
        int n = V.size();
        int mx_r = 0;
        bool OK = !V.empty();
        vector<int> res;
        for (int i = 0; i < n && mx_r < M; i++) {
            if (mx_r < V[i].le) {
                OK = false;
                break;
            }

            int mx = V[i].ri;
            int j = i;
            while(i+1 < n && V[i+1].le <= mx_r) {
                i++;
                if (V[i].ri > mx) {
                    mx = V[i].ri;
                    j = i;
                }
            }

            mx_r = max(mx_r, mx);
            res.push_back(j);
        }

        if (mx_r < M || !OK) cout << "0\n";
        else {
            int m = res.size();
            cout << m << "\n";
            for (int i = 0; i < m; i++) {
                cout << V[res[i]].le << " " << V[res[i]].ri << "\n";
            }
        }

        if (t < T) cout << "\n";
    }
    
    return 0;
}