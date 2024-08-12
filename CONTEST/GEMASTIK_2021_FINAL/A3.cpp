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

    for (auto v : adj[u]) {
        if (vis[v]) continue;

        dfs(v, u);        
        for (int i = 0; i < 20; i++) {
            if (A[u] & (1 << i)) {
                cnt_1[u][i][GANJIL] += cnt_2[v][i][GENAP];
                cnt_1[u][i][GENAP] += cnt_2[v][i][GANJIL];

                cnt_2[u][i][GANJIL] += cnt_2[v][i][GENAP];
                cnt_2[u][i][GENAP] += cnt_2[v][i][GANJIL];
            } else {
                cnt_1[u][i][GANJIL] += cnt_2[v][i][GANJIL];
                cnt_1[u][i][GENAP] += cnt_2[v][i][GENAP];

                cnt_2[u][i][GANJIL] += cnt_2[v][i][GANJIL];
                cnt_2[u][i][GENAP] += cnt_2[v][i][GENAP];
            }
        }
    }

    for (int i = 0; i < 20; i++) {
        if (A[u] & (1 << i)) cnt_2[u][i][GANJIL] += 1;
        else cnt_2[u][i][GENAP] += 1;
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

5
1 2 2 2 2
1 1 1 1
*/