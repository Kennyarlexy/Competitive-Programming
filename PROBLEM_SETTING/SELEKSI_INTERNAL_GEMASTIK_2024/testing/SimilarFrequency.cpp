#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

map<int, int> MP_1[15];
map<int, int> MP_2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        int N; cin >> N;
        for (int j = 1; j <= N; j++) {
            int x; cin >> x;
            MP_1[i][x]++;
        }

        map<int, int> MP_3;
        for (auto [x, y] : MP_1[i]) {
            MP_3[y] = 1;
        }

        for (auto [x, y] : MP_3) {
            MP_2[x]++;
        }
    }

    int mx = -1;
    for (auto [x, y] : MP_2) {
        if (y == T) mx = x;
    }

    set<int> ans;
    for (int i = 1; i <= T; i++) {
        for (auto [x, y] : MP_1[i]) {
            if (y == mx) ans.insert(x);
        }
    }

    if (ans.size() == 0) cout << "-1\n";
    else {
        cout << mx << "\n";
        for (auto an : ans) {
            cout << an << " ";
        }
        cout << "\n";
    }

    
    return 0;
}