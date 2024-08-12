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

            int mx = -1;
            int k = -1;
            int j;
            for (j = i; j < n && V[j].le <= mx_r; j++) {
                if (V[j].ri > mx) {
                    mx = V[j].ri;
                    k = j;
                }
            }

            mx_r = max(mx_r, mx);
            res.push_back(k);
            i = j-1;
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