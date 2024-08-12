#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

void dfs(int u) {
    if (vis[u]) return;

    vis[u] = true;

    for (auto v : adj[u]) {
        dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        char n; cin >> n;

        cin.ignore(10000, '\n');

        adj = vector<vector<int>> (n-'A'+1, vector<int> ());
        vis = vector<bool> (n-'A'+1);
        
        string s;
        while (true) {
            getline(cin, s);
            if (s.empty()) break;

            int u = s[0] - 'A';
            int v = s[1] - 'A';
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cnt = 0;
        for (int i = 0; i <= n-'A'; i++) {
            if (vis[i]) continue;
            dfs(i);
            cnt++;
        }

        cout << cnt << "\n";
        if (t < T) cout << "\n";
    }
    
    return 0;
}

/*
2

E
AB
CE
DB
EC

E
AB
CE
DB
EC


*/