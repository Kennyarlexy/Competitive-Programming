#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int n; cin >> n;
        map<int, int> f;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            f.insert(make_pair(a, 0));
            f[a]++;
        }

        int many = 0, single = 0;
        for (auto& num : f) {
            many += num.second >= 2;
            single += num.second == 1;
        }

        int result = many + (single + 1)/2;
        cout << result << "\n";
    }

    return 0;
}