#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

char A[200005], B[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        int x = -1, y = -1;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            if (A[i] == '1' && x == -1) x = i;
        }
        for (int j = 1; j <= n; j++) {
            cin >> B[j];
            if (B[j] == '1' && y == -1) y = j;
        }

        if (x == -1 && y == -1) cout << "YES\n";
        else if (x == -1) cout << "NO\n";
        else if (y == -1) cout << "YES\n";
        else if (x <= y) cout << "YES\n";
        else cout << "NO\n";

        
    }
    
    return 0;
}