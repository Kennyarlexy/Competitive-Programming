#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, J; cin >> N >> J;

    J = min(N, J);

    set<pair<int, int>> PQ;
    for (int i = 1; i <= N; i++) {
        int u, v; cin >> u >> v;
        PQ.insert({u*v, i});
        if (PQ.size() > J) {
            PQ.erase(PQ.begin());
        }
    }

    ll X = 0;
    vector<int> ans; ans.reserve(J);
    for (auto &[x, y] : PQ) {
        X += x;
        ans.push_back(y);
    }

    cout << X << "\n";
    for (int i = J-1; i >= 0; i--) {
        cout << ans[i];
        if (i > 0) cout << "->";
    }
    cout << "\n";
    
    return 0;
}