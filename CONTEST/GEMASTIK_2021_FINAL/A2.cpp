#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;


const int GANJIL = 1, GENAP = 0;

int A[100005];
vector<int> adj[100005];
int cnt_1[100005][20][2]; 
int cnt_2[100005][20][2]; 
bool vis[100005];
ll cnt[20];

void dfs(int u, int p) {
cout << "visiting node " << u << "\n";
    vis[u] = true;
    
    if (p != -1) for (int i = 0; i < 20; i++) {
        if (A[u] & (1 << i)) {
            cnt_1[u][i][GANJIL] = cnt_1[p][i][GENAP] + 1;
            cnt_1[u][i][GENAP] = cnt_1[p][i][GANJIL];
            cnt[i] += cnt_1[u][i][GANJIL] - 1;
        } else {
            cnt_1[u][i][GANJIL] = cnt_1[p][i][GANJIL];
            cnt_1[u][i][GENAP] = cnt_1[p][i][GENAP] + 1;
            cnt[i] += cnt_1[u][i][GANJIL];
        }
    }

// if (u == 3) for (int i = 0; i < 20; i++) {
//     cout << cnt_1[p][i][GANJIL] << "   " << cnt_1[p][i][GENAP] << "\n";
// }

if (u == 1) cout << cnt_1[u][0][GANJIL] << "   " << cnt_1[u][0][GENAP] << "\n";

    bool leaf = true;
    for (auto v : adj[u]) {
        if (vis[v]) continue;

        leaf = false;
        dfs(v, u);

        
cout << "back to node " << u << "\n";
        
        for (int i = 0; i < 20; i++) {
            if (A[u] & (1 << i)) {

if (u == 2 && i == 0) cout << cnt_2[u][i][GANJIL] << " += " << cnt_2[v][i][GENAP] + 1 << "   A\n";

                cnt_1[u][i][GANJIL] += cnt_2[v][i][GENAP];
                cnt_1[u][i][GENAP] += cnt_2[v][i][GANJIL];

                cnt_2[u][i][GANJIL] += cnt_2[v][i][GENAP] + 1;
                cnt_2[u][i][GENAP] += cnt_2[v][i][GANJIL];
            } else {

if (u == 2 && i == 0) cout << cnt_2[u][i][GANJIL] << " += " << cnt_2[v][i][GANJIL] << "   B\n";

                cnt_1[u][i][GANJIL] += cnt_2[v][i][GANJIL];
                cnt_1[u][i][GENAP] += cnt_2[v][i][GENAP] + 1;

                cnt_2[u][i][GANJIL] += cnt_2[v][i][GANJIL];
                cnt_2[u][i][GENAP] += cnt_2[v][i][GENAP] + 1;
            }
        }
    }

if (u == 1) cout << cnt_1[u][0][GANJIL] << "   " << cnt_1[u][0][GENAP] << "\n";

    if (leaf) {
        for (int i = 0; i < 20; i++) {
            if (A[u] & (1 << i)) cnt_2[u][i][GANJIL] = 1;
            else cnt_2[u][i][GENAP] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i < n; i++) {
        int v; cin >> v;
        adj[i+1].push_back(v);
        adj[v].push_back(i+1);
    }

    for (int i = 0; i < 20; i++) {
        if (A[1] & (1 << i)) cnt_1[1][i][GANJIL] = 1;
        else cnt_1[1][i][GENAP] = 1;
    }

    dfs(1, -1);

cout << "---------------------\n";
for (int i = 0; i < 20; i++) {
    cout << cnt_2[5][i][GANJIL] << "   " << cnt_2[5][i][GENAP] << "\n";
}

    ll ans = 0;
    for (int i = 0; i < 20; i++) {
        ans += (1 << i) * cnt[i];
    }

    cout << ans << "\n";
    
    return 0;
}

/*
5
1 2 3 4 5
1 2 3 4
*/