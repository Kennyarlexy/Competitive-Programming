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
        int j = -1;
        bool OK = !V.empty();
        vector<int> res;
        for (int i = 0; i < n && mx_r < M; i++) {
            if (V[i].ri <= 0) continue;
            
            if (mx_r < V[i].le) {
                if (j == -1) {
                    OK = false;
                    break;
                }
                res.push_back(j);
                mx_r = max(mx_r, V[j].ri);
                j = -1;
            }

            if (mx_r < V[i].le) {
                OK = false;
                break;
            }

            if (j == -1 || V[i].ri > V[j].ri) j = i;
        }

        if (!OK) cout << "0\n";
        else {
            if (mx_r < M) {
                if (j == -1) {
                    cout << "0\n";
                    continue;
                }

                mx_r = max(mx_r, V[j].ri);
                res.push_back(j);
            } 

            if (mx_r < M) {
                cout << "0\n";
                continue;
            }
            
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