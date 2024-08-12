#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

pair<int, int> pos[100005];

int main() {
    fast_io();
    int n, k; cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        pos[i] = {a, b};
    }

    sort(pos, pos + k);

    int res = -1;
    if (pos[0].first == 6) {
        res = 3;
    } else if (n - pos[k-1].second == 6) {
        res = n-2;
    }

    if (res == -1) {
        for (int i = 1; i < k; i++) {
            if (pos[i].first - pos[i-1].second == 6) {
                res = (pos[i].first - 3);
                break;
            }
        }
    }

    cout << res << "\n";

    return 0;
}