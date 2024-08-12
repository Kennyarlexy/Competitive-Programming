#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[100005];
bool vis[100005];
ll odd_1[100005][32]; // main odd segments
ll odd_2[100005][32]; // sub tree odd segments
ll X = 0;
ll sum = 0;
vector<int> adj[100005];

void process_1(int u, int v) {
    for (int i = 0; i < 20; i++) {
        if (A[u] & (1LL << i)) odd_1[u][i] = X - odd_1[v][i];
        else odd_1[u][i] = odd_1[v][i];   
    }
}

void process_2(int u, int v, ll Y) {
    for (int i = 0; i < 20; i++) {
        if (A[u] & (1LL << i)) {
            odd_2[u][i] += Y - odd_2[v][i];
        } else {
            odd_2[u][i] += odd_2[v][i];
        }   
        odd_1[u][i] += odd_2[u][i];
    }
}

void process_3(int u) {
    for (int i = 0; i < 20; i++) {
        if (A[u] & (1LL << i)) sum += (odd_1[u][i] - 1) * (1LL << i);
        else sum += odd_1[u][i] * (1LL << i);   
    }
}

int dfs(int u, int p) {
    vis[u] = true;
    X++;

    process_1(u, p);

    bool f = true;
    bool g = false;
    int w = -1;
    int tot_sz = 1;
    for (auto v : adj[u]) {
        if (vis[v]) continue;
        if (!g) {
            w = v;
            g = true;
            continue;
        }

        f = false;
        int sz = dfs(v, u);
        tot_sz += sz;
        
        process_2(u, v, sz+1);
    }


    if (f) {
        for (int i = 0; i < 20; i++) {
            odd_2[u][i] = (A[u] & (1LL << i)) > 0;
        }
    }

    process_3(u);
    if (g) {
        tot_sz += dfs(w, u);
    }

    return tot_sz;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int i = 2; i <= N; i++) {
        int v; cin >> v;
        adj[i].push_back(v);
        adj[v].push_back(i);
    }

    dfs(1, 0);
    cout << sum << "\n";
    
    return 0;
}