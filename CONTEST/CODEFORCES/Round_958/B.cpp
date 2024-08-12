#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

char A[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) cin >> A[i];

        vector<char> V;
        V.push_back(A[1]);
        for (int i = 2; i <= n; i++) {
            if (A[i] == '1') V.push_back(A[i]);
            else {
                if (V.back() == '0') continue;
                else V.push_back(A[i]);
            }
        }

        int m = V.size();
        int x = 0, y = 0;
        for (int i = 0; i < m; i++) {
            if (V[i] == '0') x++;
            else y++;
        }

        if (y > x) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}