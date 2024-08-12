#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        int n, m; cin >> n >> m;
        if (n == 1 && m > 2 || m == 1 && n > 2) {
            cout << "-1\n";
            continue;
        }
        int max = fmax(n-1, m-1);
        int result = 2*max - 1;
        if ((m - n) % 2 == 0) result += 1;
        cout << result << "\n";
    }

    return 0;
}