#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        int n, m; cin >> n >> m;
        int gap[n];
        for (int i = 0; i < n; i++) {
            cin >> gap[i];
        }
        int personLeft = n;
        int chairTaken = 0;
        for (int i = 0; i < n; i++) {
            chairTaken += fmax(gap[i], gap[(i+1) % n]) + 1;

            if (chairTaken > m) break;
            personLeft--;
        }
        if (personLeft > 0) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}