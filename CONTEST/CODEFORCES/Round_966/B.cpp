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
        int n; cin >> n;
        vector<int> V(n+5);
        bool OK = true;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            if (i == 1) {
                V[x] = 1;
            } else {
                if (V[x-1] + V[x+1] == 0) OK = false;
                V[x] = true;
            }
        }

        if (OK) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}