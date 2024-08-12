#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool A[25][25];
int n, m;
int ans = 0;
vector<int> V;


bool g(int i) {
    int k = V.size();
    for (int j = 0; j < k; j++) {
        if (!A[i][V[j]]) return false;
    }
    return true;
}

void f(int i) {
    if (i > n) {
        ans = max(ans, (int) V.size());
        return;
    }

    if (g(i)) {
        V.push_back(i);
        f(i+1);
        V.pop_back();
    }

    f(i+1);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        A[u][v] = true;
        A[v][u] = true;
    }

    f(1);
    cout << ans << "\n";
    
    return 0;
}