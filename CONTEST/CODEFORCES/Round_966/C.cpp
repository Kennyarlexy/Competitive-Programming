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
        map<int, vector<int>> MP;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            MP[x].push_back(i);
        }

        int m; cin >> m;
        for (int i = 1; i <= m; i++) {
            string s; cin >> s;
            int y = s.size();
            if (y != n) {
                cout << "NO\n";
                continue;
            }

            bool OK = true;
            map<char, int> MP2;
            for (auto &[x, V] : MP) {
                int k = V.size();
                MP2[s[V[0]]]++;
                if (MP2[s[V[0]]] > 1) OK = false;
                for (int j = 1; j < k; j++) {
                    if (s[V[j]] != s[V[0]]) OK = false;
                }
            }
            if (OK) cout << "YES\n";
            else cout << "NO\n";
        }

    }
    
    return 0;
}