#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

int A[2005];
bitset<2005> BS;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m; cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int x; cin >> x;
                A[x] = i;
            }
        }

        int x = 0;
        bool OK = true;
        for (int i = 1; i <= m && OK; i++) {
            BS.reset();
            for (int j = 1; j <= n; j++) {
                BS[A[x]] = 1;
                if (x >= n && A[x] != A[x-n]) {
                    OK = false;
                    break;
                }
                x++;
            }

            if (BS.count() != n) {
                OK = false;
                break;
            }
        }

        if (!OK) cout << "-1\n";
        else {
            for (int i = 0; i <= n-1; i++) {
                cout << A[i] << " \n"[i==n-1];
            }
        }
    }
    
    return 0;
}