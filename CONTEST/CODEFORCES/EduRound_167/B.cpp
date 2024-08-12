#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string a, b; cin >> a >> b;
        int n = a.length();
        int m = b.length();

        int mn = INT_MAX;
        for (int i = 0; i < m; i++) {
            int k = i;
            int x = 0;
            for (int j = 0; j < n; j++) {
                if (k < m && a[j] == b[k]) {
                    k++;
                    x++;
                }
            }

            mn = min(mn, n + m - x);
        }

        cout << mn << "\n";
    }
    
    return 0;
}

/*
1
aba
cbab
*/