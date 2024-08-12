#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int n[20][20]; // precompute
int best[20][20]; // best[i] -> best config for h = i

int dp[1000];
bitset<1000> computed;

int dpf(int h, int k, int y, int c) {
    if (y == 0) return 0;
    if (c == 0 || y < 0) return INF;

    if (computed[y]) {
        if (c < dp[y]) return INF;
        return dp[y];
    }

    int _min = INF;
    for (int i = k; i > 0; i--) {
        int move = dpf(h, k, y-best[h][i], c-1) + 1;
        _min = min(_min, move);
    }

    computed[y] = 1;
    return dp[y] = _min;
}

unordered_set<int> used;

void f(int h, int k) {
    // try new element, x, see if we can make y starting from start + 1
    int start = n[h][k-1] + 1;
    
    int max_y = start;
    int best_x = start;
    for (int x = 2; x <= start; x++) {
        if (used.count(x)) continue;
        computed.reset();
        int y = start - 1;
        best[h][k] = x; // add the element
        while (dpf(h, k, y+1, h) != INF) y++;
        if (y > max_y) {
            max_y = y;
            best_x = x;
        }
    }

    n[h][k] = max_y;
    best[h][k] = best_x;
    used.insert(best_x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // auto __time_1 = chrono::high_resolution_clock::now();
    for (int _h = 1; _h < 9; _h++) {
        n[_h][1] = _h;
        best[_h][1] = 1;
    }

    for (int h = 1; h < 9; h++) {
        used = {};
        for (int k = 2; h + k <= 9; k++) {
            f(h, k);
        }
    }

    auto __time_2 = chrono::high_resolution_clock::now();
    // chrono::duration<double, std::milli> exe_time_ms = __time_2 - __time_1;
    // cout << exe_time_ms.count() << "ms\n";
    int h, k;
    while (cin >> h >> k && h && k) {
        for (int i = 1; i <= k; i++) {
            cout << setw(3) << best[h][i];
        }
        cout << " ->" << setw(3) << n[h][k] << "\n";
    }
    // cout << "OK\n";
    
    return 0;
}