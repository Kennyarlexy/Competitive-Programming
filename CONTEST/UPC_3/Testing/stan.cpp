#include <bits/stdc++.h>
using namespace std;

int T[] = {60, 90};

tuple<int, int, int> P[10];
double dist(int x1, int y1, int x2, int y2) {
    int dx = x1 - x2;
    int dy = y1 - y2;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b; cin >> a >> b;
    for (int i = 0; i < 4; i++) {
        int x, y, z; cin >> x >> y >> z;
        P[i] = {x, y, z};
    }

    sort(P, P + 4);

    int res = INT_MAX;
    do {
        auto [x, y, z] = P[0];
        int time = (int) dist(a, b, x, y) * 60 + T[z];
        for (int i = 1; i < 4; i++) {
            auto [x1, y1, z1] = P[i-1];
            auto [x2, y2, z2] = P[i];
            time += (int) dist(x1, y1, x2, y2) * 60 + T[z2];
        }

        res = min(res, time);
    } while(next_permutation(P, P+4));
    
    cout << res << "\n";
    
    return 0;
}

/*
0 0
10 10 0
2 4 0
2 2 0
3 1 0

0 0
3 1 0
10 10 0
2 4 0
2 2 0
*/