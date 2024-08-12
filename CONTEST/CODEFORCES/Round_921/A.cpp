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
        int n, k; cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            for (char j = 'a'; j <= 'a'+k-1; j++) {
                cout << j;
            }
        }
        cout << "\n";
    }
    
    return 0;
}