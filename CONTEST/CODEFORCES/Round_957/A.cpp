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
        int a, b, c; cin >> a >> b >> c;

        int mx = INT_MIN;
        for (int i = 0; i <= 5; i++) {
            for (int j = 0; j <= 5; j++) {
                for (int k = 0; k <= 5; k++) {
                    if (i + j + k > 5) continue;
                    
                    mx = max(mx, (a+i)*(b+j)*(c+k));
                }
            }
        }

        cout << mx << "\n";
    }
    
    return 0;
}