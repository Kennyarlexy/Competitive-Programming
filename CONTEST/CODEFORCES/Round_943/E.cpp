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
        cout << "1 1\n";
        cout << n << " " << n << "\n";
        if (n >= 3) cout << "2 1\n";
        int c = n-1;
        for (int i = 4; i <= n; i++) {
            cout << "1 " << c << "\n";
            c--;
        }
        cout << "\n";
    }
    
    return 0;
}