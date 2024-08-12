#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

int A[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        cout << "1 ";
        while (n > 1) {
            int x = n/2 + 1;
            int k = n-x+1;
            for (int i = 1; i <= k; i++) {
                cout << x++ << " ";
            }
            n -= k;
        }
        cout << "\n";
    }
    
    return 0;
}