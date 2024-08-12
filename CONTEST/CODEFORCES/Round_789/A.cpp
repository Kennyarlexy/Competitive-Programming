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
    for (int t = 1; t <= T; t++) {
        set<int> distinct;
        int countZero = 0;
        int hasSame = false;
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (a == 0) countZero++;
            else if (distinct.find(a) != distinct.end()) hasSame = true;
            else distinct.insert(a);
        }
        if (countZero > 0) {
            int result = n - countZero;
            cout << result << "\n";
        } else {
            int result = (hasSame ? n : n + 1);
            cout << result << "\n";
        }
    }

    return 0;
}