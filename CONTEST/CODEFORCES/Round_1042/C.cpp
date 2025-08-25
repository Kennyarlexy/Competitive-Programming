#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, k; cin >> n >> k;
        map<int, int> MP;
        
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            MP[x%k]++;
        }

        bool OK = true;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            x %= k;
            if (MP[x] == 0 && MP[k-x] == 0) {
                OK = false;
            }

            if (MP[x] > 0) {
                MP[x]--;
            } else {
                MP[k-x]--;
            }
        }

        if (OK) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}