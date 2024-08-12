#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        vector<int> faulty;
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int k; cin >> k;
            if (k != i) faulty.push_back(k);
        }

        unsigned int result = UINT_MAX;
        for (auto& data : faulty) {
            result = result & data;
        }
        cout << result << "\n";
    }

    return 0;
}